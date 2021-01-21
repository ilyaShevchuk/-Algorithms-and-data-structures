fin = open("input.txt")
n = int(fin.readline())
lst = fin.readlines()
lst = [[int(n) for n in x.split()] for x in lst]


def check(lst):
    flag = 1
    for i in range(n):
        for j in range(n):
            if (i == j) and (lst[i][j] == 1):
                flag = 0
                return flag
            if (lst[i][j] == 1) and (lst[j][i] == 0):
                flag = 0
                return flag
    return flag


main_flag = check(lst)
fout = open("output.txt", "w")

if main_flag == 1:
    fout.write("YES")
else:
    fout.write("NO")