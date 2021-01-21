fin = open("search1.in")
p = fin.readline().strip()
t = fin.readline().strip()
results = []
for i in range(len(t) - len(p)+1):
    if t[i:len(p) + i] == p:
        results.append(i+1)
fout = open("search1.out", "w")
fout.write(str(len(results)) + '\n')
for index in results:
    fout.write(str(index) + ' ')
fout.close()
fin.close()
