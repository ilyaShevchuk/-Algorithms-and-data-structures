def merge_break(lst):
    if len(lst) <= 1:
        return lst
    middle = int( len(lst) / 2 )   
    left = merge_break(lst[:middle])
    right = merge_break(lst[middle:])
    result = merge(left, right)
    return result


def merge(left, right):
    result = []
    cnt = 0
    i, j = 0, 0
    while i < len(left) and j < len(right):
        if left[i][0] < right[j][0]:
            result.append(left[i])
            i += 1
        elif(left[i][0]>right[j][0]):
            result.append(right[j])
            j += 1
        else:
            if left[i][1] > right[j][1]:
                result.append(right[j])
                j+=1
            else:
                result.append(left[i])
                i+=1
    result += left[i:]
    result += right[j:]
    return result 

file = open('race.in')
k = int(file.readline())
cty = []
for i in range(k):
    s1,s2 = file.readline().split()
    tup = (s1,i,s2)
    cty.append(tup)
cty2 = merge_break(cty)
i = 1
file2 = open('race.out','w')
file2.write('=== ')
file2.write(cty2[0][0])
file2.write(' ===\n')
file2.write(cty2[0][2])
file2.write('\n')
while i <= len(cty2)-1:
    if cty2[i][0] != cty2[i-1][0]: 
        file2.write('=== ')
        file2.write(cty2[i][0])
        file2.write(' ===\n')
        file2.write(cty2[i][2])
        file2.write('\n')
    else:
        file2.write(cty2[i][2])
        file2.write('\n')
    i+=1
file2.close()
file.close()