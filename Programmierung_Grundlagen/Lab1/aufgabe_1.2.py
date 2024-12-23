def Teilfolge(list,n):
    num=0
    count=0

    list.sort()
    v=[]
    v.append(list[0])

    for i in range(1,n):
        if(list[i]!=list[i-1]):
            v.append(list[i])

    for i in range(len(v)):
        if(i>0 and v[i]==v[i-1]+1):
            count+=1

        else:
            count = 1
        num=max(num, count)

    return num


list = [4,1,2,2,3]
n=len(list)

print('Longest subsequence: ', Teilfolge(list,n))
