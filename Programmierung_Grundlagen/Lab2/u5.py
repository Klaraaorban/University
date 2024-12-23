def bez(list, x):
    v = []
    for i in list:
        s = i
        n = s % 10
        m = s // 10
        try:
            if eval(x) == True:
                v.append(i)
        except ZeroDivisionError:
            pass
    return v
sor = [12, 23,56,77,12]
n=str(input('relatia: '))
print(bez(sor,n))
