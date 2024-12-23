#Primzahlen

def primzahl(num):
    if(num==0 or num == 1):
        return False
    for i in range(2,num):
        if(num%i==0):
            return False

    return True


zahl=12
for i in range(1,zahl+1):
    if(primzahl(i)):       
        print(i, end=" ")

