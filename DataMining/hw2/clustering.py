from sklearn import cluster, datasets, metrics
import math
import matplotlib.pyplot as plt
import pandas as pd
from pandas.core.frame import DataFrame
import numpy as np
from sklearn import preprocessing

# 先把資料讀進來
data = pd.read_csv('./data.csv').values[:,1:]
test_data = pd.read_csv('./test.csv').values[:,1:]

# 把數字正規化
scaler = preprocessing.MinMaxScaler(feature_range=(0, 1))
data = scaler.fit_transform(data)
data = pd.DataFrame(data)

# 使用四種不同的方式來分類，然後記錄下來
labels = []
labels.append(cluster.SpectralClustering(n_clusters = 6 ,random_state = 1, affinity='rbf', gamma = 0.3, n_init=100).fit(data).labels_)
labels.append(cluster.AgglomerativeClustering(n_clusters = 5, linkage = 'ward', compute_full_tree= True).fit(data).labels_)
labels.append(cluster.KMeans(n_clusters = 3, init = 'k-means++', n_init = 100, max_iter = 30000, tol = 1e-4, random_state=1, precompute_distances=True).fit(data).labels_)
labels.append(cluster.MiniBatchKMeans(n_clusters = 6, n_init = 100).fit(data).labels_)

# 最後來投票，只要大於等於2的就算同類
ans = np.zeros((len(test_data), len(labels)))
for i in range(len(test_data)):
    for j in range(len(labels)):
        if(labels[j][test_data[i][0]] == labels[j][test_data[i][1]]):
            ans[i][j] = 1
ans = np.array(ans)
ans = np.sum(ans, axis = 1)
ans = (ans) > 1

# 輸出結果
submit = [['index', 'ans']]
for i in range(len(test_data)):
    submit.append([int(i), str(int(ans[i]))])
submit = DataFrame(submit)
submit.to_csv("submit.csv", header=None, index=False, encoding='utf-8')
