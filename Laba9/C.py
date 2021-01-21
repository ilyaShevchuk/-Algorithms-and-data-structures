file = open("bipartite.in")
n, m = map(int, file.readline().split())
adj = [[]for i in range(0, n+1)]
for i in range(m):
    b, c = map(int, file.readline().split())
    if c not in adj[b]:
        adj[b].append(c)
    if b not in adj[c]:
        adj[c].append(b)

level = [-1] * (len(adj))


def bfs(s, new_level):
    global level
    level[s] = new_level
    queue = [s]
    while len(queue) != 0:
        v = queue.pop(0)
        if level[v] == 0:
            new_level = 1
        else:
            new_level = 0
        for w in adj[v]:
            if level[w] == -1:
                queue.append(w)
                level[w] = new_level
            elif level[w] != new_level:
                return False
    return True


for i in range(1, len(adj)):
    if level[i] == -1:
        flag = bfs(i, 0)
        if flag == False:
            file2 = open("bipartite.out", 'w')
            file2.write("NO")
            file2.close()
            file.close()
            exit()


file2 = open("bipartite.out", 'w')
print("YES", file=file2)
file2.close()
file.close()
