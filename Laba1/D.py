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
file = open('smallsort.in')
k = file.readline().strip()
mas = file.readline().strip()
k2 = int(k)
masiv = []
masiv.append(mas.split())
masiv2 = masiv[0]
 
for i in range(k2):
    masiv2[i] = int(masiv2[i])
masiv2 = quicksort(masiv2)
file2 = open('smallsort.out','w')
file2.write(' '.join(map(str,masiv2)))
file2.close()

file.close()