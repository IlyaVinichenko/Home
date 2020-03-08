import numpy as np
from scipy.spatial.distance import euclidean

def knn_predict_simple(X, y, x, k):
    distances = [(y[i], euclidean(x, X[i])) for i in range(len(X))]
    distances.sort(key=lambda i: i[1])
    answer = [distances[i][0] for i in range(k)]
    index, value = np.unique(answer, return_counts=True)
    return list(zip(index, value))

def knn_new(X, y, x, k):
    dist = np.linalg.norm(X-x, axis=1)
    idx_sort = dist.argsort()
    answer = y[idx_sort[:k]]
    index, value = np.unique(answer, return_counts=True)
    return list(zip(index, value))