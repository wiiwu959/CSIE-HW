#!/usr/bin/env python
# coding: utf-8

import os, math
from math import log, pow, sqrt
from numba import jit
from tqdm import tqdm 
import numpy as np
from scipy.sparse import coo_matrix

# read query list and doc list
with open('./ntust-ir-2020_hw4_v2/query_list.txt', 'r') as fp:
    query_list = fp.read()
query_list = query_list.splitlines()

with open('./ntust-ir-2020_hw4_v2/doc_list.txt', 'r') as fp:
    doc_list = fp.read()
doc_list = doc_list.splitlines()


# read file and store them in to dict
total_word_count = 0
word_doc_num = {}
doc_word = {}
for doc in doc_list:
    with open('./ntust-ir-2020_hw4_v2/docs/' + doc + '.txt', 'r') as fp:
        doc_content = fp.read()
    doc_content = doc_content.split(' ')
    doc_word[doc] = doc_content
    for word in doc_content:
        if word not in word_doc_num:
            word_doc_num[word] = {}
        if doc not in  word_doc_num[word]:
            word_doc_num[word][doc] = 0
        word_doc_num[word][doc] += 1
    total_word_count += len(doc_content)
        
word_query_num = {}
query_word = {}
for query in query_list:
    with open('./ntust-ir-2020_hw4_v2/queries/' + query + '.txt', 'r') as fp:
        query_content = fp.read()
    query_content = query_content.split(' ')
    query_word[query] = query_content
    for word in query_content:
        if word not in word_query_num:
            word_query_num[word] = {}
        if query not in  word_query_num[word]:
            word_query_num[word][query] = 0
        word_query_num[word][query] += 1


# use for getting initial random probability
def get_random_p(row, col):
    temp = np.abs(np.random.randn(row, col))
    temp /= temp.sum(axis=1, keepdims=True)
    return temp


# e_step
@jit(nopython=True)
def e_step(i_j_tf_row, i_j_tf_col, i_j_tf_data, p_t_wd, p_w_t, p_t_d):
    for k in range(topic_num):
        for p in range(len(i_j_tf_data)):
            sum_p_t_wd = 0
            for kk in range(topic_num):
                sum_p_t_wd += p_w_t[i_j_tf_row[p]][kk] * p_t_d[kk][i_j_tf_col[p]]
            p_t_wd[k][p] = p_w_t[i_j_tf_row[p]][k] * p_t_d[k][i_j_tf_col[p]] / sum_p_t_wd
    return p_t_wd


# m_step
@jit(nopython=True)
def m_step(i_j_tf_row, i_j_tf_col, i_j_tf_data, p_t_wd, p_w_t, p_t_d):
    p_w_t.fill(0)
    p_t_d.fill(0)
    for k in range(topic_num):
        sum_c_p = 0
        sum_c = np.zeros(len(p_t_d[k]))
        
        for p in range(len(i_j_tf_data)):
            c_p = i_j_tf_data[p] * p_t_wd[k][p]
            p_w_t[i_j_tf_row[p]][k] += c_p
            p_t_d[k][i_j_tf_col[p]] += c_p
            
            
            sum_c_p += c_p
            sum_c[i_j_tf_col[p]] += i_j_tf_data[p]
            
        for i in range(len(p_w_t)):
            p_w_t[i][k] = p_w_t[i][k] / sum_c_p
            
    for k in range(topic_num):
        for j in range(len(p_t_d[k])):
            p_t_d[k][j] = p_t_d[k][j] / sum_c[j]
                   
    return p_w_t, p_t_d

# use sparse matrix to store non-zero i, j, and tf
word_list = list(word_doc_num.keys())

i_list = []
j_list = []
tf_list = []

for i in tqdm(range(len(word_list))):
    for j in range(len(doc_list)):
        if doc_list[j] in word_doc_num[word_list[i]]:
            i_list.append(i)
            j_list.append(j)
            tf_list.append(word_doc_num[word_list[i]][doc_list[j]])
i_j_tf = coo_matrix((np.array(tf_list), (np.array(i_list), np.array(j_list))))


# assign topic number, random seed, and em iterate times and do em
topic_num = 32

i_j_tf_row = i_j_tf.row
i_j_tf_col = i_j_tf.col
i_j_tf_data = i_j_tf.data
np.random.seed(729)
p_t_wd = np.zeros(shape = (topic_num, len(i_j_tf_data)))
p_w_t = get_random_p(len(word_list),topic_num)
p_t_d = get_random_p(topic_num, len(doc_list))

for it in tqdm(range(150)):
    p_t_wd = e_step(i_j_tf_row, i_j_tf_col, i_j_tf_data, np.array(p_t_wd), np.array(p_w_t), np.array(p_t_d))
    p_w_t, p_t_d = m_step(i_j_tf_row, i_j_tf_col, i_j_tf_data, np.array(p_t_wd), np.array(p_w_t), np.array(p_t_d))


# count all pwd, pwbg and store them to make code faster
p_w_d = []
p_w_bg = []
for i in tqdm(range(len(word_list))):
    temp = []
    for j in range(len(doc_list)):
        val = 0
        if doc_list[j] in word_doc_num[word_list[i]]:
            val = word_doc_num[word_list[i]][doc_list[j]] / len(doc_word[doc_list[j]])
        temp.append(val)
    p_w_d.append(temp)
    
    bg_up = 0
    for doc, num in word_doc_num[word_list[i]].items():
        bg_up += num
    p_w_bg.append(bg_up / total_word_count)


# calculate final result
alpha = 0.7
beta = 0.2

ans = {}
for query in tqdm(query_list):
    if query not in ans:
        ans[query] = {}
    for j in range(len(doc_list)):
        p_q_dj = 0
        for each_word in query_word[query]:
            i = word_list.index(each_word)
            bg_up = 0
            for doc, num in word_doc_num[word_list[i]].items():
                bg_up += num

            middle = 0
            for k in range(topic_num):
                middle += p_w_t[i, k] * p_t_d[k, j]
                
            p_q_dj += log(alpha * p_w_d[i][j] + beta * middle + (1 - alpha - beta) * p_w_bg[i])
        ans[query][doc_list[j]] = p_q_dj


# output result to file
f = open('result.txt', 'w+')
f.write('Query,RetrievedDocuments\n')

for query in query_list:
    print_ans = query + ','
    temp_ans = sorted(ans[query].items(), key=lambda x:x[1],reverse=True)
    for i in temp_ans:
        print_ans += i[0] + ' '
    print_ans = print_ans[:-1] + '\n'
    f.write(print_ans)

f.close()


# In[ ]:


sorted(ans['301'].items(), key=lambda x:x[1],reverse=True)


# In[ ]:




