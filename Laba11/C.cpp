#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <set>
using namespace std;
const int INF = 10000001;

vector<int> way(vector < vector < pair<int, int> > > &g, int start, int n){
    vector<int> d (n, INF),  p (n);
    d[start] = 0;
    set < pair<int,int> > q;
    q.insert (make_pair (d[start], start));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase (q.begin());

        for (size_t j=0; j<g[v].size(); ++j) {
            int to = g[v][j].first,
                    len = g[v][j].second;
            if (d[v] + len < d[to]) {
                q.erase (make_pair (d[to], to));
                d[to] = d[v] + len;
                p[to] = v;
                q.insert (make_pair (d[to], to));
            }
        }
    }
    return d;
}
int main() {
    int n, m, x1, x2, w;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ofstream fout("pathbgep.out");
    ifstream fin("pathbgep.in");
    fin>>n>>m;
    vector < vector < pair<int,int> > > graph (n, vector < pair<int, int>> () );
    for (size_t i = 0; i < m; ++i) {
        fin >> x1 >> x2 >> w;
        graph[x1-1].push_back(make_pair(x2-1, w));
        graph[x2-1].push_back(make_pair(x1-1,w));
    }
    vector<int> result(n);
    result = way(graph, 0, n);
        for (size_t j = 0; j < result.size(); j++)
            if (result[j] == INF)
                fout<<-1<<' ';
            else
            fout<<result[j]<<' ';
        fout<<endl;
    fout.close();
    fin.close();
    return 0;
}
