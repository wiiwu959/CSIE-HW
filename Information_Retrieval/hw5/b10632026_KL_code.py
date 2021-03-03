import os, math
from math import log, pow, sqrt
from numba import jit
from tqdm import tqdm 
import numpy as np
from scipy.sparse import coo_matrix
from sklearn.metrics.pairwise import cosine_similarity
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.feature_extraction.text import CountVectorizer

# Origin VSM
with open('./ntust-ir-2020_hw5_new/query_list.txt', 'r') as fp:
    query_list = fp.read()
query_list = query_list.splitlines()

with open('./ntust-ir-2020_hw5_new/doc_list.txt', 'r') as fp:
    doc_list = fp.read()
doc_list = doc_list.splitlines()


total_word_count = 0

word_doc_num = {}
doc_word = {}
for doc in doc_list:
    with open('./ntust-ir-2020_hw5_new/docs/' + doc + '.txt', 'r') as fp:
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
    with open('./ntust-ir-2020_hw5_new/queries/' + query + '.txt', 'r') as fp:
        query_content = fp.read()
    query_content = query_content.split(' ')
    query_word[query] = query_content
    for word in query_content:
        if word not in word_query_num:
            word_query_num[word] = {}
        if query not in  word_query_num[word]:
            word_query_num[word][query] = 0
        word_query_num[word][query] += 1
        
        
# make a list of all words
total_word = []
for word, num in word_query_num.items():
    total_word.append(word)
for word, num in word_doc_num.items():
    total_word.append(word)
total_word = list(dict.fromkeys(total_word))

# count max df
max_df = 0
for a, b in word_doc_num.items():
    if len(b) > max_df:
        max_df = len(b)
        
        
# count tfidf of each word in all of the doc
doc_word_tfidf = {}
doc_length = {}
for doc, content in doc_word.items():
    doc_word_tfidf[doc] = {}
    doc_len_2 = 0
    for word in content:
        if word not in doc_word_tfidf[doc]:
            # 0.70924
            tf = 1 + log(word_doc_num[word][doc])
            idf = log(1 + max_df / len(word_doc_num[word]))
            
            doc_word_tfidf[doc][word] = tf * idf
            doc_len_2 += pow(tf * idf, 2)
    doc_length[doc] = sqrt(doc_len_2)
    
# count tfidf of each word in all of the query
query_word_tfidf = {}
query_length = {}
for query, content in query_word.items():
    query_word_tfidf[query] = {}
    query_len_2 = 0
    for word in content:
        if word not in query_word_tfidf[query]:
            # 0.70924
            tf = 1 + log(word_query_num[word][query])
            idf = log(1 + max_df / len(word_doc_num[word])) if word in word_doc_num else 0
            
            query_word_tfidf[query][word] = tf * idf
            query_len_2 += pow(tf * idf, 2)
    query_length[query] = sqrt(query_len_2)
    
# count the cosine using data we pre-calculate before
first_result = {}
for query in query_list:
    for doc in doc_list:
        cossim = 0
        for word, tfidf in query_word_tfidf[query].items():
            cossim = cossim + (tfidf * doc_word_tfidf[doc][word]) if word in doc_word_tfidf[doc] else cossim
        if query not in first_result:
            first_result[query] = {}
        first_result[query][doc] = cossim / (doc_length[doc] * query_length[query])


# modified VSM
with open('./ntust-ir-2020_hw5_new/query_list.txt', 'r') as fp:
    query_list = [line.rstrip() for line in fp]

with open('./ntust-ir-2020_hw5_new/doc_list.txt', 'r') as fp:
    doc_list = [line.rstrip() for line in fp]

documents, queries = [], []

for doc_name in doc_list:
    with open('./ntust-ir-2020_hw5_new/docs/' + doc_name + '.txt', 'r') as fp:
        doc_content = fp.read()
        documents.append(doc_content)

for query_name in query_list:
    with open('./ntust-ir-2020_hw5_new/queries/' + query_name + '.txt', 'r') as fp:
        query_content = fp.read()
        queries.append(query_content)

vectorizer = TfidfVectorizer(smooth_idf=True, sublinear_tf=True)
vectorizer.fit(queries + documents)
doc_tfidf = vectorizer.fit_transform(documents).toarray()
query_tfidf = vectorizer.transform(queries).toarray()

cos_sim = cosine_similarity(query_tfidf, doc_tfidf)
result = np.flip(cos_sim.argsort(), axis=1)


# KL Divergent
smm_alpha = 0.9
alpha = 0.3
beta = 0.8
gamma = 0.7
select_rel = 5
e_m_round = 10

new_queries = []

for query_result in result:
    new_queries.append(' '.join([documents[i] for i in query_result[:select_rel]]))

counter = CountVectorizer()
counter.fit(queries + documents)
query_tf = counter.transform(queries).toarray()
new_query_tf = counter.transform(new_queries).toarray()
doc_tf = counter.transform(documents).toarray()

word_list = counter.get_feature_names()

# init possibility
def get_random_p(row, col):
    np.random.seed(314)
    temp = np.abs(np.random.randn(row, col))
    temp /= temp.sum(axis=1, keepdims=True)
    return temp

P_SMM_w = get_random_p(len(query_list),len(word_list)) # 150 * 154209
P_w_BG = doc_tf.sum(axis = 0) / doc_tf.sum() # 154209 one-vector
P_ULM_w_q = query_tf / query_tf.sum(axis=1).reshape(-1,1) # 150 * 154209
P_ULM_w_dj = doc_tf / doc_tf.sum(axis=1).reshape(-1,1) # 150 * 154209

@jit(nopython=True)
def e_m_step(P_SMM_w, P_w_BG):
    P_T_SMM_w = ((1 - smm_alpha) * P_SMM_w) / ((1 - smm_alpha) * P_SMM_w + smm_alpha * P_w_BG)  # 150 * 154209
    return (new_query_tf * P_T_SMM_w) / ((new_query_tf * P_T_SMM_w).sum(axis = 1).reshape(-1,1))  

for i in tqdm(range(e_m_round)):
    P_SMM_w = e_m_step(P_SMM_w, P_w_BG)

P_w_q = alpha * P_ULM_w_q + beta * P_SMM_w + (1 - alpha - beta) * P_w_BG # 150 * 154209
P_w_dj = gamma * P_ULM_w_dj + (1 - gamma) * P_w_BG # 30000 * 154209
last_result = (P_w_q.dot(np.log(P_w_dj).T)) * -1
last_result = np.argsort(last_result)

f = open('smm_9_3_8_7_5.txt', 'w+')
f.write('Query,RetrievedDocuments\n')
for query_name, query_result in zip(query_list, last_result):
    doc_result = ' '.join([doc_list[i] for i in query_result])
    f.write('%s,%s\n' % (query_name, doc_result))