#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
using namespace std;

const long long INF = 8e18;
int vertex_count;
int edge_count;
int start;
int finish;
bool flag = false;
struct Edge {
    long to;
    long from;
    long long length;
};
vector<Edge> graph;
vector<long long> weights;

vector <bool> visited;
void Read() {
    ifstream input;
    input.open("path.in", ios_base::in);
    input >> vertex_count >> edge_count >> start;
    start--;
    weights.resize(vertex_count, INF);
    visited.resize(vertex_count, false);
    weights[start] = 0;
    for (int i = 0; i < edge_count; i++)
    {
        int a, b;
        long long d;
        input >> a >> b >> d;
        graph.push_back({b - 1, a - 1, d});
    }
    input.close();
}

void DFS(int begin, vector<bool> &visited)
{
    visited[begin] = true;
    for (int i = 0; i < edge_count; i++)
    {
        if ((!visited[graph[i].to]) && (graph[i].from == begin))
            DFS(graph[i].to, visited);
    }
}
void check(int a) {


    DFS(a, visited);
    for (int i = 0; i < vertex_count; i++)
        if (visited[i])
            weights[i] = -INF;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ofstream output;
    output.open("path.out", ios_base::out);
    Read();
    vector<int> parents(vertex_count, -1);
    unordered_set<int> possible_cycles;
    int lastChanged;
    for (int k = 0; k < vertex_count + 2; k++)
    {
        lastChanged = -1;
        for (int i = 0; i < edge_count; i++)
        {
            if ((graph[i].length + weights[graph[i].from] < weights[graph[i].to])&&(weights[graph[i].from] != INF))
            {

                weights[graph[i].to] = max(graph[i].length + weights[graph[i].from], -INF);
                parents[graph[i].to] = graph[i].from;
                if (k > vertex_count)
                {
                    lastChanged = graph[i].to;
                    possible_cycles.insert(graph[i].to);
                }
            }

        }
    }
    while (!possible_cycles.empty())
    {
        for (int j = 0; j < vertex_count; j++)
        {
            lastChanged = parents[lastChanged];
            possible_cycles.erase(lastChanged);
        }
        check(lastChanged);
        lastChanged = *(possible_cycles.begin());
        possible_cycles.erase(lastChanged);
    }
    for (int i = 0; i < vertex_count; i++)
    {
        switch (weights[i])
        {
            case INF:
                output << "*\n";
                break;
            case -INF:
                output << "-\n";
                break;
            default:
                output << weights[i] << "\n";
                break;
        }
    }
    output.close();
    return 0;
}