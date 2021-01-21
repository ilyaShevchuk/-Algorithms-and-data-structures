def sift(list, heap_size, parent):  
    largest = parent
    left_child = (2 * parent) + 1
    right_child = (2 * parent) + 2
    if (left_child < heap_size) and (list[left_child] > list[largest]):
        largest = left_child
    if (right_child < heap_size) and (list[right_child] > list[largest]):
        largest = right_child
    if largest != parent:
        list[parent], list[largest] = list[largest], list[parent]
        sift(list, heap_size, largest)


def heap_sort(list):
    n = len(list)
    for i in range(n, -1, -1):
        sift(list, n, i)
    for j in range(n - 1, 0, -1):
        list[j], list[0] = list[0], list[j]
        sift(list, j, 0)


file = open('sort.in')
m = int(file.readline())
mas = file.readline().split()
for qu in range(m):
    mas[qu] = int(mas[qu])
heap_sort(mas)
file1 = open('sort.out', 'w')
for zu in range(m):
    file1.write(str(mas[zu]))
    file1.write(' ')
