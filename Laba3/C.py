file = open('isheap.in')
n = int(file.readline())
lst = file.readline().split()
for i in range(n):
    lst[i] = int(lst[i])
i = 0
while i < n//2 + n%2:
    if (2*i+1 < n) and (lst[i] > lst[2*i+1]):
        break
    if (2*i + 2 < n) and (lst[i] > lst[2 * i + 2]):
        break
    i += 1

file2 = open('isheap.out', 'w')
if (i != n//2 + n%2):
    file2.write('NO')
else:
    file2.write('YES')