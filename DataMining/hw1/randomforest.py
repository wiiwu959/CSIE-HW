import pandas as pd
import numpy as np
from sklearn import preprocessing
from sklearn.utils import shuffle
from sklearn.ensemble import RandomForestClassifier
from pandas.core.frame import DataFrame

# 讀進資料
train_data = pd.read_csv('./train.csv')
test_data = pd.read_csv('./test.csv')

# 把有缺項的資料丟掉
train_data = train_data.dropna(axis=0,how='any')

# 按照Attribute23，分成'Yes'和'No'的兩群資料
train_data = train_data.groupby('Attribute23')
no_data = train_data.get_group('No')
yes_data = train_data.get_group('Yes')

# no的資料比yes的資料多，所以把yes和no的資料弄成一樣的
# 再把他們合起來打亂
no_data = no_data.sample(len(yes_data))
train_data = pd.concat([no_data, yes_data], axis = 0)
train_data = shuffle(train_data)

# 把train的結果拿出來
# test的資料合在一起做one hot(確保兩個用的是同樣的one hot結果)
# 順便把明顯沒用的資料丟了(日期)
train_result = train_data.values[:,-1]
train_data = train_data.drop(['Attribute23'], axis = 1)    # axis刪除行用0,列用1,default是0
concat_data = pd.concat([train_data, test_data], axis = 0)
concat_data = concat_data.drop(['Attribute1'], axis = 1)
concat_data = pd.get_dummies(data = concat_data, columns = ['Attribute8', 'Attribute10', 'Attribute11', 'Attribute22'])

# 做完one hot了把他們拆回本來的train_data和test_data
concat_data = concat_data.values
train_data = concat_data[:len(train_data),:]
test_data = concat_data[-len(test_data):,:]

# 把train_result中的'Yes'和'No'換成(1,0)
train_result = np.where(train_result =='Yes', 1, 0)

# train model
forest = RandomForestClassifier(criterion='entropy', n_estimators = 165, random_state = 1, oob_score=True)
forest.fit(train_data, train_result)

# randomforest對train data的正確率
print('score', forest.score(train_data,train_result))
print('oob_score',forest.oob_score_)

# 預測test.csv
model_ans = []
model_ans = forest.predict(test_data)

true_amount = 0
false_amount = 0
submit = [['id', 'ans']]
for i in range(len(model_ans)):
    submit.append([float(i), str(int(model_ans[i]))])
    if(model_ans[i] == True):
        true_amount += 1
    else:
        false_amount += 1

print('true:',true_amount,', false:', false_amount)

submit = DataFrame(submit)
submit.to_csv("submit.csv", header=None, index=False, encoding='utf-8')
