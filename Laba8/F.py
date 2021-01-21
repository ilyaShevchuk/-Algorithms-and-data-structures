file = open("input.txt")
n, m = map(int, file.readline().split())
lines = file.readlines()
adj = [[] for i in range(0, n * m)]
for i in range(n):
    for j in range(m):
        if lines[i][j] != '#':
            if (j < m - 1) and (lines[i][j + 1] != '#'):
                adj[i * m + j].append(i * m + j + 1)
            if (j > 0) and (lines[i][j - 1] != '#'):
                adj[i * m + j].append(i * m + j - 1)
            if (i < n - 1) and (lines[i + 1][j] != '#'):
                adj[i * m + j].append((i + 1) * m + j)
                adj[(i + 1) * m + j].append(i * m + j)
        if lines[i][j] == 'S':
            start = i * m + j
        if lines[i][j] == 'T':
            finish = i * m + j

level = [-1] * (len(adj))


def bfs(s, x):
    global level
    level[s] = s
    queue = [s]
    while len(queue) != 0:
        v = queue.pop(0)
        for w in adj[v]:
            if level[w] == -1:
                queue.append(w)
                level[w] = level[v] + 1


bfs(start, finish)
help_level = finish
fin = level[finish]
star = level[start]
search = level[finish]
mas_way = []
if level[finish] == -1:
    file_out = open("output.txt", "w")
    file_out.write("-1")
    file_out.close()
    exit()
while search != star:
    mas = []
    for i in range(len(adj[help_level])):
        if level[adj[help_level][i]] == search - 1:
            level_down = adj[help_level][i]
    mas_way.append(level_down)
    help_level = level_down
    search -= 1
mas_way.reverse()
mas_way.append(finish)
mas_way_output = []
for i in range(len(mas_way)-1):
    if mas_way[i+1] - mas_way[i] == m:
        mas_way_output.append('D')
    elif mas_way[i+1] - mas_way[i] == -m:
        mas_way_output.append('U')
    elif mas_way[i+1] - mas_way[i] == 1:
        mas_way_output.append('R')
    else:
        mas_way_output.append('L')
file_out = open("output.txt", "w")
file_out.write(str(len(mas_way_output)) + '\n')
for i in range(len(mas_way_output)):
    file_out.write(mas_way_output[i])
file_out.close()
file.close()