def reverse_paar(n):
    s=0
    if n!=0:
        s=(n%10)*10 + n//10
    return s
def sym_paar(sor):
    count=0
    for i in range(len(sor)):
        option=sor[i]
        for j in range(len(sor)):
            if sor[j] == reverse_paar(option):
                count +=1
        return count

arr=[23, 32, 44, 56, 32]
print(sym_paar(arr))
