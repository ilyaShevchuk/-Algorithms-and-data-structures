with open('turtle.in', 'r') as file:
    h,w = file.readline().strip().split()
    w = int(w)
    h = int(h)
    lst = file.readlines()
lst = [[int(n) for n in x.split()] for x in lst]
i = h-1
while i != 0 :
    lst[i-1][0] += lst[i][0]
    i -=1
j = 0
while j != w-1:
    lst[h-1][j+1]+=lst[h-1][j]
    j+=1
i = 0
j = 0
for i in range(h-2,-1,-1):
    for j in range(1,w,1):
        if lst[i+1][j]>lst[i][j-1]:
            lst[i][j] += lst[i+1][j]
        else:
            lst[i][j] += lst[i][j-1]

file2 = open('turtle.out','w')
file2.write(str(lst[0][w-1]))
file2.close()
file.close()