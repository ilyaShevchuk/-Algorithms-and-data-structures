def merge_cnt_inv(lst):
    if len(lst) <= 1:
        return lst, 0
    middle = int( len(lst) / 2 )
    left, a = merge_cnt_inv(lst[:middle])
    right, b = merge_cnt_inv(lst[middle:])
    result, c = merge(left, right)
    return result, (a + b + c)

def merge(left, right):
    result = []
    cnt = 0
    i, j = 0, 0
    left_len = len(left)
    while i < left_len and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            cnt += left_len - i
            j += 1
    result += left[i:]
    result += right[j:]
    return result, cnt 
def cnt_inv(lst):
    return merge_cnt_inv(lst)[1]


with open('inversions.in', 'r') as file:
    size = file.readline()
    size = int(size)
    lst = file.readline().split()
for i in range(size):
    lst[i] = int(lst[i])
k = cnt_inv(lst)
file2 = open('inversions.out','w')
file2.write(str(k))
file2.close()

