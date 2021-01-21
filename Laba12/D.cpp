#include <fstream>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

struct Edge {
    int to, capacity, flow;
};
vector<vector<int>> graph;
vector<Edge> edges;
vector<int> ptr;
vector<int> levels;
int n = 0, m = 0, source = 0, sink = 0;

bool bfs() {
    levels.assign(n, 0);
    queue<int> q;
    q.push(source);
    levels[source] = 1;
    while (!q.empty() && !levels[sink]) {
        int from = q.front();
        q.pop();
        for (auto& edge : graph[from]) {
            if (!levels[edges[edge].to] && edges[edge].capacity > edges[edge].flow) {
                q.push(edges[edge].to);
                levels[edges[edge].to] = levels[from] + 1;
            }
        }
    }
    return levels[sink];
}

int dfs(int vertex = source, int flow = INT_MAX) {
    if (!flow)
        return 0;
    if (vertex == sink)
        return flow;
    while (ptr[vertex] < graph[vertex].size()) {
        int edge = graph[vertex][ptr[vertex]];
        if (levels[vertex] + 1 == levels[edges[edge].to]){
            int pushed = dfs(edges[edge].to, min(flow, edges[edge].capacity - edges[edge].flow));
            if (pushed) {
                edges[edge].flow += pushed;
                edges[edge ^ 1].flow -= pushed;
                return pushed;
            }
        }
        ptr[vertex]++;
    }
    return 0;
}

void add(int from, int to, int capacity) {
    graph[from].push_back(edges.size());
    edges.emplace_back(Edge{to, capacity, 0});
    graph[to].push_back(edges.size());
    edges.emplace_back(Edge{from, 0, 0 });
}

int main() {
    ifstream fin("circulation.in");
    ofstream fout("circulation.out");
    fin >> n >> m;
    n += 2;
    graph.resize(n);
    ptr.resize(n, 0);
    sink = n - 1;
    for (int i = 0; i < m; i++) {
        int from, to, lowFlow, highFlow;
        fin >> from >> to >> lowFlow >> highFlow;
        add(source, to, lowFlow);
        add(from, to, highFlow - lowFlow);
        add(from, sink, lowFlow);
    }
    while (bfs()) {
        while (dfs());
        ptr.assign(n, 0);
    }
    for (int edge : graph[0]) {
        if (edges[edge].flow < edges[edge].capacity) {
            fout << "NO\n";
            return 0;
        }
    }
    fout << "YES\n";
    for (int i = 0; i < edges.size(); i += 6)
        fout << edges[i + 2].flow + edges[i + 4].flow << endl;
    return 0;
}