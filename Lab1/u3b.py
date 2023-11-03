def primzahl(num):
    if(num==0 or num == 1):
        return False
    for i in range(2,num):
        if(num%i==0):
            return False

    return True

l=[1,2,5,6,7,9,11]
count=0
for i in range(len(l)):
    if(primzahl(l[i])):
        count+=1

print(count)
