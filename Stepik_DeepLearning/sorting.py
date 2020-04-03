# Хитрая сортировка
 

# Пусть у нас есть следующий список, в котором элементы -- tuple из строк:

# items = [('one', 'two'), ('three', 'four'), ('five', 'six'), ('string', 'a')]
# Мы хотим отсортировать этот список по последней букве второго элемента каждого tuple, т.е. получить такой список:

# sorted_items = [ ('string', 'a'), ('one', 'two'), ('three', 'four'), ('five', 'six'),]
# Что нужно вставить вместо "<...>" в следующем выражении, чтобы получить верную сортировку?

# sorted_items = sorted(items, key=lambda x: <...>)
 

# P.S.: в ответе не должно фигурировать слово len

# Напишите программу. Тестируется через stdin → stdout
# Time Limit: 15 секунд
# Memory Limit: 256 MB

# https://docs.python.org/3/howto/sorting.html

# items объявлять не нужно
sorted_items = sorted(items, key=lambda x: x[1][-1])