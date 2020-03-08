import numpy as np

def linear_func(theta, x):
    return np.dot(theta, x) # Функция dot() вычисляет скалярное произведение двух массивов.
def linear_func_all(theta, X):
    return np.array([linear_func(theta, x) for x in X])
def mean_squared_error(theta, X, y):
    return sum(pow(y - linear_func_all(theta, X), 2)) / len(X)
def grad_mean_squared_error(theta, X, y):
    return 