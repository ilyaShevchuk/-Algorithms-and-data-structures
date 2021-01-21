file = open("components.in")
n, m = map(int, file.readline().split())
print(n, m)
adj = [[]for i in range(0, n+1)]
for i in range(m):
    b, c = map(int, file.readline().split())
    adj[b].append(c)
    adj[c].append(b)

level = [-1] * (len(adj))


def bfs(s, comps1):
    global level
    level[s] = s
    queue = [s]
    comps1.append(s)
    while len(queue) != 0:
        v = queue.pop(0)
        for w in adj[v]:
            if level[w] is -1:
                queue.append(w)
                comps1.append(w)
                level[w] = level[v] + 1
    return comps1

k = 0
components = [0 for i in range(n)]
for i in range(1, len(adj)):
    comps = []
    if level[i] is -1:
        comps = bfs(i, comps)
        k += 1
        for j in range(len(comps)):

            components[comps[j]-1] = k
file2 = open("components.out", 'w')
file2.write(str(k) + '\n')
print(" ".join(map(str, components)), file=file2)
file2.close()
file.close()

