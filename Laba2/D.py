file = open('antiqs.in')
n = file.read()
n = int(n)
mas = []
for i in range(n):
    mas.append(i+1)
for i in range(2,n):
    mas[i],mas[i//2] = mas[i//2],mas[i]
file2 = open('antiqs.out','w')
file2.write(' '.join(map(str,mas)))
file.close()
file2.close()

