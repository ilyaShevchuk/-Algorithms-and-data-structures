file1 = open('radixsort.in')
n, m1, k = file1.readline().split()
n = int(n)
m1 = int(m1)
k = int(k)
lst = []
for qu in range(n):
    y = file1.readline().split()
    lst.append(y[0])
k = m1 -k
l = m1 - 1

def radix(mas, j):
    counts = [0] * 26
    for i1 in range(n):
        x = ord(mas[i1][j]) - 97
        counts[x] += 1
    sums = 0
    for i2 in range(26):
        if counts[i2] != 0:
            counts[i2] += sums
            sums += counts[i2] - sums
    lst2 = [0] * n
    for zu in range(26):
        let = zu + 97
        if counts[zu] != 0:
            for p in range(n-1, -1, -1):
                if ord(mas[p][j]) == let:
                    lst2[counts[zu] - 1] = mas[p]
                    counts[zu] -= 1
    j = j - 1
    if j >= k:
        radix(lst2, j)
    else:
        for op in range(n):
            file2.write(lst2[op] + '\n')
        return lst2


file2 = open('radixsort.out', 'w')
lst3 = radix(lst, l)