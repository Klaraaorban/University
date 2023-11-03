from math import gcd

def zahlen(n):
    l=[]
    for i in range(1,n):
        if gcd(n,i)==1:
            l.append(i)
    return l

if __name__=='__main__':
    n=13
    result=zahlen(n)
    print(result)

