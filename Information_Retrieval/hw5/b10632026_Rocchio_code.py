import os, math
from math import log, pow, sqrt
from tqdm import tqdm 
import numpy as np
from sklearn.metrics.pairwise import cosine_similarity

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

first_result = {}
for query in query_list:
    for doc in doc_list:
        cossim = 0
        for word, tfidf in query_word_tfidf[query].items():
            cossim = cossim + (tfidf * doc_word_tfidf[doc][word]) if word in doc_word_tfidf[doc] else cossim
        if query not in first_result:
            first_result[query] = {}
        first_result[query][doc] = cossim / (doc_length[doc] * query_length[query])


result = {}

alpha = 1
beta = 0.9
gamma = 0.1
select_num = 5

for query in tqdm(query_list):
    if query not in result:
        result[query] = {}
    
    vector_key = query_word[query]
    for i in sorted(first_result[query].items(), key=lambda x:x[1],reverse=True)[:select_num]:
        vector_key += doc_word[i[0]]
    for i in sorted(first_result[query].items(), key=lambda x:x[1],reverse=True)[-select_num:]:
        vector_key += doc_word[i[0]]
    vector_key = list(dict.fromkeys(vector_key))
    
    relevant = np.zeros(shape=(len(vector_key)))
    first_query = np.zeros(shape=(len(vector_key)))
    nonrelevant = np.zeros(shape=(len(vector_key)))
    for i in range(len(vector_key)):
        first_query[i] += query_word_tfidf[query].get(vector_key[i], 0)
        for doc in sorted(first_result[query].items(), key=lambda x:x[1],reverse=True)[:select_num]:
            relevant[i] += doc_word_tfidf[doc[0]].get(vector_key[i], 0)
        for doc in sorted(first_result[query].items(), key=lambda x:x[1],reverse=True)[-select_num:]:
            nonrelevant[i] += doc_word_tfidf[doc[0]].get(vector_key[i], 0)
    new_query = alpha * first_query + beta * (relevant / select_num) - gamma * (nonrelevant / select_num)
        
    for doc in doc_list:
        doc_vector = np.zeros(shape=(len(vector_key)))
        for i in range(len(vector_key)):
            doc_vector[i] += doc_word_tfidf[doc].get(vector_key[i], 0)
        result[query][doc] = cosine_similarity(new_query.reshape(1, -1), doc_vector.reshape(1, -1))
        

f = open('result_9_1_5.txt', 'w+')
f.write('Query,RetrievedDocuments\n')
for query in query_list:
    print_ans = query + ','
    temp_result = sorted(result[query].items(), key=lambda x:x[1],reverse=True)
    for i in temp_result:
        print_ans += i[0] + ' '
    print_ans = print_ans[:-1] + '\n'
    f.write(print_ans)
f.close()