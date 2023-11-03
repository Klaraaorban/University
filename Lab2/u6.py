def domino(list):
    count = 0
    v = []
    for i in range(len(list)):
        n = list[i-1] % 10
        m = list[i]
        m = m // 10
        if n == m:
            count += 1
            v.append(list[i])
    return count, ' : '  ,v


sor = [11, 12, 23, 36, 67, 77,67, 89]
print(domino(sor))
