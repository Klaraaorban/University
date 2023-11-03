def n_prime(n):
    prim = [2]
    num = 3
    while len(prim) < n:
        tester=True
        for i in range(len(prim)):
            if num%prim[i]==0:
                tester=False
                break
        if tester:
            prim.append(num)
        num+=2

    for i in range(len(prim)):
        print(prim[i], end=" ")

n=5
n_prime(5)
