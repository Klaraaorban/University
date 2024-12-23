def kgf(list):
    k = list[0]
    for i in range(1, len(list)-1):
        a = k
        b = list[i]
        lnko = 1
        while b != 0:
            m = b
            b = a % b
            a = m
        lnko = a
        k = (k * list[i]) // lnko
    return k

list1 = [1, 2, 8, 3]
print(kgf(list1))

