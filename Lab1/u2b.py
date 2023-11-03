def relativ_prim(a,b):
    m=min(a,b)
    for i in range(1,m+1):
        if a%i==0 and b%i==0:
            count=i
    if count==1:
        return True
    return False

num=0
count=0

def rel_Teilfolge(list):
    list.sort()
    v=[]
    v.append(list[0])
    for i in range(1,len(list)):
        if(relativ_prim(list[i],list[i+1])):
            v.append(list[i])

    for i in range(1,len(v)):
        if(i>0 and relativ_prim(v[i],v[i-1])):
            count+=1
        else:
            count=1
            num=max(num,count)
    return num

list=[2,3,7,10]
print(rel_Teilfolge)


