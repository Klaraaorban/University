def rel_prim(num):
    l = []
    if num == 1:
        return [1]
    else:
        for oszt in range(2, num + 1):
            if num % oszt == 0:
                l.append(oszt)
    return l


def teilfolge(liste):
    l = []
    max_l = []
    longest = liste[0]
    for i in liste[1:]:
        con = True
        longest_last = rel_prim(longest)
        longest_now = rel_prim(i)
        if l == []:
            l.append(longest)
        for j in longest_last:
            if j in longest_now:
                con = False
        if con == True:
            l.append(i)
        else:
            l = []
        if len(l) > len(max_l):
            max_l = l
        longest = i
    return max_l



sor = [1, 2, 3, 4, 5, 6, 12, 1, 2]
print(teilfolge(sor))
