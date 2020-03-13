import numpy as np

def gini(y):
    # y: одномерный np.array — значения классов в обучающей выборке
    # gigni = 1 - Σ (pi)^2
    # pi - probability; Σ range(1, n + 1)
    number_of_occurrences = np.unique(y, return_counts=True)[1]
    probability = number_of_occurrences / len(y)
    return 1-np.sum([pow(p, 2) for p in probability])