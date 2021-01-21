file = open('binsearch.in', 'r')
n = int(file.readline())
lst = file.readline().split()
for i in range(n):
    lst[i] = int(lst[i])
m = int(file.readline())
vals = file.readline().split()
for i in range(m):
    vals[i] = int(vals[i])


def bin_search1(mas, left, right, x):
    if left > right:
        return -1
    mid = (left + right) // 2
    if mas[mid] == x:
        if (mid == 0) or (mas[mid-1] != x):
            return mid
        else:
            return bin_search1(mas, left, mid-1, x)

    elif mas[mid] > x:
        return bin_search1(mas, left, mid - 1, x)
    else:
        return bin_search1(mas, mid + 1, right, x)


def bin_search2(mas, left, right, x):
    if left > right:
        return -1
    mid = (left + right) // 2

    if mas[mid] == x:
        if (mid == right) or (mas[mid+1] != x):
            return mid
        else:
            return bin_search2(mas, mid+1, right, x)
    elif mas[mid] >= x:
        return bin_search2(mas, left, mid - 1, x)
    else:
        return bin_search2(mas, mid + 1, right, x)


file1 = open('binsearch.out', 'w')
for i in range(m):
    a1 = bin_search1(lst, 0, n - 1, vals[i])
    a2 = bin_search2(lst, 0, n - 1, vals[i])
    if a1 != -1:
        a1+=1
    if a2 != -1:
        a2+=1
    file1.write(str(a1))
    file1.write('  ')
    file1.write(str(a2))
    file1.write('\n')

file1.close()
file.close()