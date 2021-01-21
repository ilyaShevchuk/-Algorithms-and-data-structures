file = open("pathbge1.in")
n, m = map(int, file.readline().split())
adj = [[]for i in range(0, n+1)]
for i in range(m):
    b, c = map(int, file.readline().split())
    adj[b].append(c)
    adj[c].append(b)

level = [-1] * (len(adj))


def minus(x):
    return x-1


def bfs(s):
    global level
    level[s] = s
    queue = [s]
    while len(queue) != 0:
        v = queue.pop(0)
        for w in adj[v]:
            if level[w] == -1:
                queue.append(w)
                level[w] = level[v] + 1


for i in range(1, len(adj)):
    if level[i] is -1:
        bfs(i)


file2 = open("pathbge1.out", 'w')
level = list(map(minus, level))
print(" ".join(map(str, level[1::])), file=file2)
file2.close()
file.close()