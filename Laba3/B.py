def garland(A, n):
    left = 0
    right = A
    mas = [0] * n
    mas[0] = A
    while right - left > 0:
        mas[1] = (left+right) / 2
        middle = mas[1]
        if (middle == left) or (middle == right):
            break
        flag = 1
        for i in range(2, n, 1):
            mas[i] = 2 * mas[i-1] - mas[i-2] + 2
            if mas[i] <= 0:
                flag = 0
                break
        if flag == 1:
            right = middle
        else:
            left = middle
    return mas[n-1]


file1 = open('garland.in')
file2 = open('garland.out', 'w')
n, a = file1.readline().split()
a = float(a)
n = int(n)
result = round(garland(a, n), 2)
file2.write(str(result))
file1.close()
file2.close()
