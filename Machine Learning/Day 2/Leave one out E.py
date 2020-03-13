import numpy as np

# Выборка разбивается на l−1 и 1 объект l раз.
# каждый объект ровно один раз участвует в контроле

def loo_score(predict, X, y, k):
# predict — функция predict(X, y, x, k) , обучающая некоторый алгоритм на выборке X, y с параметром k и дающая предсказание на примере x
# X — двумерный np.array — обучающая выборка
# y — реальные значения классов в обучающей выборке
# k — количество соседей, которые нужно рассматривать
    score = 0
    a = np.arange(len(X))
    y = np.array(y)
    for i in range(len(X)):
        if predict(X[a != i], y[a != i], X[i], k) == y[i]:
            score += 1
    return score