import numpy as np

def linear_func(theta, x):
    return x @ theta

def linear_func_all(theta, X):
    return X @ theta

def mean_squared_error(theta, X, y):
    return np.mean((y - linear_func_all(theta, X))**2)
    
def grad_mean_squared_error(theta, X, y):
    f = linear_func_all(theta, X)
    return np.mean(2 * (f - y) * X.T, axis=1)