#include<iostream>
#include <list>
#include <stack>
#include <fstream>


using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    
    bool Cyclic_small(int v, bool visited[], bool *grey_Stack);
    void top_sort_small(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);
    void add_edge(int v, int w);
    void top_sort_big();
    bool Cyclic_big();
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
bool Graph::Cyclic_small(int v, bool visited[], bool *grey_Stack)
{
    if(visited[v] == false)
    {
        visited[v] = true;
        grey_Stack[v] = true;

        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && Cyclic_small(*i, visited, grey_Stack) )
                return true;
            else if (grey_Stack[*i])
                return true;
        }

    }
    grey_Stack[v] = false;
    return false;
}

bool Graph::Cyclic_big()
{
    bool *visited = new bool[V];
    bool *grey_Stack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        grey_Stack[i] = false;
    }

    for(int i = 0; i < V; i++)
        if (Cyclic_small(i, visited, grey_Stack))
            return true;

    return false;
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

    ofstream out("topsort.out");
    while (Stack.empty() == false)
    {

        if (Stack.top() != 0){
            out << Stack.top() << " ";
            Stack.pop();
        }
        else{
            Stack.pop();
            out.close();
        }
    }
}


int main()
{
    ifstream fin("topsort.in");
    int n, m, x, y;
    fin>>n>>m;
    Graph g(n+1);
    for(int i = 0; i < m;i++){
        fin>>x>>y;
        g.add_edge(x, y);
    }
    if (g.Cyclic_big() == true){
        ofstream out("topsort.out");
        out<<-1;
    }
    else {
        g.top_sort_big();
    }
    return 0;
} 