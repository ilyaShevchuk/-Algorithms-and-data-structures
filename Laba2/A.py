import random
def quicksort(mas):
   if len(mas) <= 1:
       return mas
   else:
       q = random.choice(mas)
   mas_1 = [n for n in mas if n < q]
   mas_2 = [q] * mas.count(q)
   mas_3 = [n for n in mas if n > q]
   return quicksort(mas_1) + mas_2 + quicksort(mas_3)
with open('sort.in', 'r') as file:
    size = file.readline()
    size = int(size)
    lst = file.readline().split()
for i in range(size):
    lst[i] = int(lst[i])
lst = quicksort(lst)
file2 = open('sort.out','w')
file2.write(' '.join(map(str,lst)))
