# https://stepik.org/lesson/316052/step/11?unit=301794

def cumsum_and_erase(A, erase = 1):
    B = []
    point = 0
    for i in range(len(A)):
        point += A[i]
        if point != erase:
            B.append(point)
    return B