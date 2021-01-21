def BFS(g, s, t, parent):
    visited = [False] * len(g)
    queue = [s]
    visited[s] = True

    while queue:
        u = queue.pop(0)
        for ind in range(len(g[u])):
            if visited[ind] == False and graph[u][ind] > 0:
                queue.append(ind)
                visited[ind] = True
                parent[ind] = u

    return True if visited[t] else False


def FordFulkerson(graph, source, sink):
    parent = [-1] * (len(graph))
    max_flow = 0
    while BFS(graph, source, sink, parent):
        path_flow = float("Inf")
        s = sink

        while s != source:
            path_flow = min(path_flow, graph[parent[s]][s])
            s = parent[s]

        max_flow += path_flow
        v = sink

        while v != source:
            u = parent[v]
            graph[u][v] -= path_flow
            graph[v][u] += path_flow
            v = parent[v]
    return max_flow


file1 = open("maxflow.in")
n, m = map(int, file1.readline().split())
graph = [[0 for i in range(n)] for j in range(n)]
for line in range(m):
    x, y, weight = map(int, file1.readline().split())
    graph[x - 1][y - 1] = weight
src, snk = 0, n-1
file2 = open("maxflow.out", 'w')
file2.write(str(FordFulkerson(graph, src, snk)))
