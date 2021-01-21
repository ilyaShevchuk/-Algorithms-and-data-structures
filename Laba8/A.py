file = open("input.txt")
n, m = file.readline().split()
n = int(n)
m = int(m)
a = [[0] * n for i in range(n)]
for i in range(m):
    b, c = file.readline().split()
    b = int(b)
    c = int(c)
    b -= 1
    c -= 1
    a[b][c] = 1
file2 = open("output.txt", "w")
for i in range(n):
    for j in range(n):
        file2.write(str(a[i][j]))
        file2.write(' ')
    file2.write('\n')