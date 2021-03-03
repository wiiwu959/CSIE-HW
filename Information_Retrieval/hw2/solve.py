#!/usr/bin/env python
import os, math
from math import log, pow, sqrt

# read list txt
with open('query_list.txt', 'r') as fp:
    query_list = fp.read()
query_list = query_list.splitlines()

with open('doc_list.txt', 'r') as fp:
    doc_list = fp.read()
doc_list = doc_list.splitlines()


# read document and query files
word_doc_num = {}
doc_word = {}
for doc in doc_list:
    with open('./docs/' + doc + '.txt', 'r') as fp:
        doc_content = fp.read()
    doc_content = doc_content.split(' ')
    doc_word[doc] = doc_content
    for word in doc_content:
        if word not in word_doc_num:
            word_doc_num[word] = {}
        if doc not in  word_doc_num[word]:
            word_doc_num[word][doc] = 0
        word_doc_num[word][doc] += 1
        
word_query_num = {}
query_word = {}
for query in query_list:
    with open('./queries/' + query + '.txt', 'r') as fp:
        query_content = fp.read()
    query_content = query_content.split(' ')
    query_word[query] = query_content
    for word in query_content:
        if word not in word_query_num:
            word_query_num[word] = {}
        if query not in  word_query_num[word]:
            word_query_num[word][query] = 0
        word_query_num[word][query] += 1


# use some weird method
total_query = []
for word, other in word_query_num.items():
    if word not in total_query:
        total_query.append(word)

temp_word_doc_num = {}
temp_doc_word = {}
for word, other in word_doc_num.items():
    if word in total_query:
        temp_word_doc_num[word] = other
        
for doc, other in doc_word.items():
    temp_doc_word[doc] = []
    for word in other:
        if word in total_query:
            temp_doc_word[doc].append(word)
word_doc_num = temp_word_doc_num
doc_word = temp_doc_word

# calculate average document length
avg_doclen = 0
for doc in doc_list:
    avg_doclen += len(doc_word[doc])
avg_doclen = avg_doclen / len(doc_list)

# best
def get_sim(doc, query):
    query_content = query_word[query]
    doc_content = doc_word[doc]
    sim = 0
    
    b = 0.87
    k1 = 3
    s1 = k1 + 1
    k3 = 1
    s3 = k3 + 1  
    
    k2 = 0.1
    giq = sqrt(abs(k2 * len(query_content) * (avg_doclen - len(doc_content)) / (avg_doclen + len(doc_content))))
    
    for word in query_content:
        if word in doc_content:
            tfij = word_doc_num[word][doc]
            tfiq = word_query_num[word][query]
            log_thing = log((len(doc_list) - len(word_doc_num[word]) + 0.5) / (len(word_doc_num[word]) + 0.5))
            up = (k1 + 1) * tfij * (k3 + 1) * tfiq * pow(log_thing, 1.3) 
            down = (k1*((1 - b) + (b * len(doc_content) / avg_doclen)) + tfij) * (k3 + tfiq)
            sim += giq + (up / down) ** 1.19
    return sim

# get results
result = {}
for query in query_list:
    for doc in doc_list:
        if query not in result:
            result[query] = {}
        result[query][doc] = get_sim(doc, query)


# export result to txt file
f = open('result.txt', 'w+')
f.write('Query,RetrievedDocuments\n')

for query in query_list:
    print_ans = query + ','
    temp_result = sorted(result[query].items(), key=lambda x:x[1],reverse=True)
    for i in temp_result:
        print_ans += i[0] + ' '
    print_ans = print_ans[:-1] + '\n'
    f.write(print_ans)

f.close()