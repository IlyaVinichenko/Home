def process(sentences):
    result = []
    for i in sentences:
        sentence = i.split()
        sent = []
        for part in sentence:
            if part.isalpha():
                sent.append(part)
        result.append(" ".join(sent))
    return result
# test case
# Пример ввода:

# ['1 thousand devils', 'My name is 9Pasha', 'Room #125 costs $100']

# Пример вывода: 

# ['thousand devils', 'My name is', 'Room costs']

print(process(['1 thousand devils', 'My name is 9Pasha', 'Room #125 costs $100']))