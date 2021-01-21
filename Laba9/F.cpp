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
    bool check(int start);
    vector<bool> first_win;
};

Graph::Graph(int V)
    :first_win(V, false)
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

bool Graph::check(int start) {
    for (int i = result.size() - 1; i >= 0 ; i--){
        int u = result[i];
        if (adj[u].size() == 0)
            first_win[u] = false;
        else
            for (int j = i + 1; j < result.size(); j++){
                for ( int v: adj[result[i]])
                    if (first_win[v] == false){
                        first_win[result[i]] = true;
                        break;
                }
        }
    }
    if (first_win[start] == false)
        return false;
    else
        return true;

}

int main() {
    ifstream fin("game.in");
    ofstream out("game.out");
    int n, m, x, y, s;
    fin >> n >> m >>s;
    Graph g(n + 1);
    for (int i = 0; i < m; i++) {
        fin >> x >> y;
        g.add_edge(x, y);
    }
    g.top_sort_big();
    bool flag = g.check(s);
    if (flag)
        out<<"First player wins";
    else
        out<<"Second player wins";
    return 0;

}