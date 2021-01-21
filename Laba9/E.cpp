#include<iostream>
#include <list>
#include <stack>
#include <fstream>
#include <vector>

using namespace std;
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    auto it = v.cbegin();
    auto end = v.cend();

    os << "[";
    if (it != end) {
        os << *it;
        it = std::next(it);
    }
    while (it != end) {
        os << ", " << *it;
        it = std::next(it);
    }
    return os << "]";
}
class Graph
{
    int V;
    void top_sort_small(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);
    list<int> *adj;
    vector<int> result;
    void add_edge(int v, int w);
    void top_sort_big();
    bool check();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::add_edge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::top_sort_small(int v, bool visited[],
                           stack<int> &Stack)
{
    visited[v] = true;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            top_sort_small(*i, visited, Stack);

    Stack.push(v);
}


void Graph::top_sort_big()
{
    stack<int> Stack;

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            top_sort_small(i, visited, Stack);

    while (Stack.empty() == false)
    {

        if (Stack.top() != 0){
            result.push_back(Stack.top());
            Stack.pop();
        }
        else{
            Stack.pop();
        }
    }
}

bool Graph::check() {
    for (int i = 0; i < result.size() - 1; i ++) {
        int flag = 0;
        for (int u:adj[result[i]])
            if (u == result[i + 1])
                flag = 1;
        if (flag == 0)
            return false;
    }
    return true;
}

int main()
{
    ifstream fin("hamiltonian.in");
    int n, m, x, y;
    fin>>n>>m;
    Graph g(n+1);
    for(int i = 0; i < m;i++){
        fin>>x>>y;
        g.add_edge(x, y);
    }
    g.top_sort_big();
    bool big_flag = g.check();
    ofstream out("hamiltonian.out");
    if (big_flag == 1)
        out<<"YES";
    else
        out<<"NO";
    out.close();
    return 0;
}