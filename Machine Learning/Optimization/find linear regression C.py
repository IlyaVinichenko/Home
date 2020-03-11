import numpy as np

def fit_linear_regression(X, y):
    b = np.linalg.inv(X.T @ X) @ X.T @ y
    return b
