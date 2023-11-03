def schlussel(list):
    v = []
    b =[]
    c = []
    for i in range(len(list)):
        number=list[0]
        list.pop(0)
        for j in range(len(list)):
            list[j] = list[j] + number
        v.append(list)
        for m in range(len(list)):
            list[m] = list[m] * number
        b.append(list)
        for n in range(len(list)):
            list[n] = list[n] ^ number
        c.append(list)
        return ' + ',v, ' * ',b, ' ^ ', c

sor=[10,23,56,11,90]
print(schlussel(sor))
