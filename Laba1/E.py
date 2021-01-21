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
file = open('sortland.in')
k = file.readline().strip()
mas = file.readline().strip()
k2 = int(k)
masiv = []
masiv.append(mas.split())
masiv2 = masiv[0]
for i in range(k2):
    masiv2[i] = float(masiv2[i])
masiv3 = []
masiv3 += masiv2
masiv2.sort()
a = 0
b = 0
c = 0
for i in range(k2):
    if masiv2[0] == masiv3[i]:
        a = i
    if masiv2[k2-1] == masiv3[i]:
        b = i
    if masiv2[k2//2] == masiv3[i]:
        c = i
file2 = open('sortland.out','w')
s = ''
s = s + str(a+1) + ' ' +   str(c+1) + ' ' + str(b+1)
file2.write(s)
file2.close()
file.close()