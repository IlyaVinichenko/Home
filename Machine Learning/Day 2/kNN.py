import numpy as np

def knn_predict_simple(X, y, x, k):
    dist = np.linalg.norm(X-x, axis=1)
    idx_sort = dist.argsort()
    answer = y[idx_sort[:k]]
    index, value = np.unique(answer, return_counts=True)
    return list(zip(index, value))