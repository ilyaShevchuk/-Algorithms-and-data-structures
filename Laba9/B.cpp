#include<iostream>
#include <list>
#include <fstream>
#include <vector>

using namespace std;

class Graph
{
    int V;
    vector<int> *adj;
    bool Cyclic_small(int v);
public:
    int *used;
    int *way;
    int cycle_st, cycle_end;
    Graph(int V);
    void add_edge(int v, int w);
    bool Cyclic_big();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int>[V];
    used = new int[V];
    way = new int[V];
}

void Graph::add_edge(int v, int w)
{
    adj[v].push_back(w);
}


bool Graph::Cyclic_small(int v)
{
    this->used[v] = 1;
    for(int i = 0; i < adj[v].size(); ++i)
    {
        int to = adj[v][i];
        if (this->used[to] == 0){
            this->way[to] = v;
            if (Cyclic_small(to))
                return true;
        }
        else if (this->used[to] == 1){
            this->cycle_end = v;
            this->cycle_st = to;
            return true;
        }
    }

    this->used[v] = 2;
    return false;
}

bool Graph::Cyclic_big()
{

    for(int i = 0; i < V; i++)
    {
        this->used[i] = 0;
        this->way[i] = -1;
    }

    for(int i = 1; i < V; i++)
        if (Cyclic_small(i))
            return true;

    return false;
}


int main()
{
    ifstream fin("cycle.in");
    ofstream out("cycle.out");
    int n, m, x, y;
    fin>>n>>m;
    Graph g(n+1);
    for(int i = 0; i < m;i++){
        fin>>x>>y;
        g.add_edge(x, y);
    }
    bool flag = g.Cyclic_big();
    int find = g.cycle_st;
    if (flag == 1){
        out<<"YES"<<endl;
        out<<g.cycle_end<<' ';
        while(find != g.cycle_end){
            for(int i = 1; i < n+1; i++){
                if(g.way[i] == find){
                    find = i;
                    out<<g.way[i]<<' ';
                }
            }
        }
    }
    else
        out<<"NO";
    return 0;
}