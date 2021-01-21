file = open("input.txt")
n, m = map(int, file.readline().split())
adj = [[]for i in range(0, n+1)]
for i in range(m):
    b, c = map(int, file.readline().split())
    adj[b].append(c)
    adj[c].append(b)
result = []
for j in range(1, len(adj)):
    result.append(len(adj[j]))
file2 = open("output.txt", 'w')
print(" ".join(map(str, result)), file=file2)
file2.close()
file.close()
