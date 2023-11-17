def primzahl(num):
    if (num == 0 or num == 1):
        return False
    for i in range(2, num):
        if (num % i == 0):
            return False

    return True

"""
s = []
l = [1, 2, 5, 17, 7, 6, 7, 9, 11]
z = 0
for i in range(len(l) - 1):
    if primzahl(l[i]) and primzahl(l[i+1]):
        s.append(l[i])
        z = l[i+1]
s.append(z)
print(s)
"""

def primeseq(list):
    max_l = []
    l = []
    for i in range(len(list)):
        if primzahl(list[i]):
            l.append(list[i])
        else:
            if len(l) > len(max_l):
                max_l = l
                l = []
    if len(l) > len(max_l):
        max_l = l
    return max_l

l = [1, 2, 5, 17, 7, 6, 4, 15, 7, 11, 13, 17, 19, 23]
print(primeseq(l))
