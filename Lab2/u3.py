"""
l=[12,45]
konk: 5421
"""
def konkatenation(list):
    option=0
    v=[]
    k=0
    p=10
    l=0
    for i in range(len(list)):
        s=list[i]
        n=s%10
        m=s//10
        v.append(n)
        v.append(m)
    v.sort()
    v.reverse()
    for j in v:
        k= k*p + j
    p*=10

    return v,k

sor=[23,85]
print(konkatenation(sor))
