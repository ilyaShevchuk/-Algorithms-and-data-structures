file = open("input.txt")
n, m = file.readline().split()
n = int(n)
m = int(m)
a = [[0] * n for i in range(n)]
main_flag = 0
for i in range(m):
    b, c = file.readline().split()
    b = int(b)
    c = int(c)
    b -= 1
    c -= 1
    if a[b][c] == 1:
        main_flag = 3
    a[b][c] = 1


def check(lst):
    flag = 0
    for i in range(n):
        for j in range(n):
            if (lst[i][j] == 1) and (lst[j][i] == 1):
                flag = 1
                return flag
    return flag


if main_flag != 3:
    main_flag = check(a)


fout = open("output.txt", "w")

if main_flag == 1 or main_flag == 3:
    fout.write("YES")
else:
    fout.write("NO")