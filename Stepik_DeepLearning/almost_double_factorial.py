# Почти двойной факториал

# Реализуйте функцию almost_double_factorial(n), вычисляющую произведение всех нечётных натуральных чисел, не превосходящих n.
# В качестве аргумента ей передаётся натуральное (ноль -- натуральное) число n ⩽100.
# Возвращаемое значение - вычисленное произведение.

 

# Комментарий. В случае, если n = 0, требуется вывести 1.

# Напишите программу. Тестируется через stdin → stdout
# Time Limit: 15 секунд
# Memory Limit: 256 MB

def almost_double_factorial(n):
    if n == 0:
        return 1
    else:
        numbers = [number for number in range(n+1) if number % 2 != 0]
        result = 1
        for i in range(len(numbers)):
            result = result * numbers[i]
        return result