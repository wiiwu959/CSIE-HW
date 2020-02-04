import numpy as np
import pandas as pd
from sklearn import preprocessing
from mlxtend.frequent_patterns import apriori
from mlxtend.frequent_patterns import association_rules
import pickle
from pandas.core.frame import DataFrame

def encode_units(x):
    if x <= 0:
        return 0
    if x >= 1:
        return 1

data = pd.read_excel("data.xlsx")
data['Description'] = data['Description'].str.strip()

# 把InvoiceNo有缺的都丟掉
data.dropna(axis=0, subset=['InvoiceNo'], inplace=True)

# 把被取消的交易丟掉(InvoiceNo開頭為C的)
data['InvoiceNo'] = data['InvoiceNo'].astype('str')
data = data[~data['InvoiceNo'].str.contains('C')]

data = (data[data['Country'] == 'United Kingdom']
          .groupby(['InvoiceNo', 'Description'])['Quantity']
          .sum().unstack().reset_index().fillna(0)
          .set_index('InvoiceNo'))

# DATA 中出現負值統一以 0 取代
data = data.applymap(encode_units)

# 去除 POSTAGE 的 row
data.drop('POSTAGE', inplace=True, axis=1)

# support ≥ min threshold(0.01)，confidence ≥ min threshold(0.5)
frequent_itemsets = apriori(data, min_support=0.01, use_colnames=True, low_memory=True)
rules = association_rules(frequent_itemsets, metric="lift", min_threshold=0.5)
# 測試時加速用的
# rules.to_pickle('associate.pkl') 
# rules.to_csv('associate.csv') 
# with open('associate.pkl', 'rb') as f:
#     rules = pickle.load(f)

submit_format = pd.read_csv("prediction.csv")
ans = []

# 將 antecedants 和 consequents 轉成 list
ant = rules['antecedents']
con = rules['consequents']
ant = [list(x) for x in ant]
con = [list(x) for x in con]

for i in range(len(submit_format)):
    # 將submit的antecedants和consequents用', '切開
    sub_ant = submit_format['Association Rule antecedents'][i].split(', ')
    sub_con = submit_format['Association Rule consequents'][i].split(', ')
    find = False
    for j in sub_ant:
        find = False
        for k in sub_con:
            if (j != '' and k != ''):
                for a in range(len(ant)):
                    if (j in ant[a] and k in con[a]):
                        find = True
                        break
                if (find == False):
                    break
            else:
                continue
        if(find == False):
            break
    if (find == False):
        ans.append(0)
    else: 
        ans.append(1)

submit = [['index', 'label']]
for i in range(len(ans)):
    submit.append([int(i), str(int(ans[i]))])
submit = DataFrame(submit)
submit.to_csv("submit.csv", header=None, index=False, encoding='utf-8')

# data = data.reset_index(drop=True)
# https://blog.csdn.net/lujiandong1/article/details/52929090