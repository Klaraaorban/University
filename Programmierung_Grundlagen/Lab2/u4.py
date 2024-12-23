def schlussel(list):
    v = []
    b =[]
    c = []
    for i in range(len(list)):
        number=list[0]
        list.pop(0)
        for j in range(len(list)):
            x = list[j] + number
            v.append(x)
        for m in range(len(list)):
            y = list[m] * number
            b.append(y)
        for n in range(len(list)):
            z = list[n] ^ number
            c.append(z)
        return ' + ',v, ' * ',b, ' ^ ', c

sor=[10,23,56,11,90]
print(schlussel(sor))
