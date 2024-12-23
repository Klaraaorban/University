def wiederholen(list):
    count=0
    list.sort()
    new_list=[]
    for i in range(len(list)):
        if list[i] not in new_list:
            new_list.append(list[i])
    return new_list

numbers=[1,2,2,4,5,8,4,3]
print(wiederholen(numbers))
