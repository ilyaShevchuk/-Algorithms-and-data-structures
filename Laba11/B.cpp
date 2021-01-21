#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;
const long long INF = 9223372036854775806;

vector<long long> way(vector < vector < pair<long long, long long> > > &g, int start, int n){
    vector<long long> d (n, INF),  p (n);
    d[start] = 0;
    vector<char> u (n);
    for (long long i=0; i<n; ++i) {
        long long v = -1;
        for (long long j=0; j<n; ++j)
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        if (d[v] == INF)
            break;
        u[v] = true;

        for (size_t j=0; j<g[v].size(); ++j) {
            long long to = g[v][j].first,
                    len = g[v][j].second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
    return d;
}
int main() {
    long long n, m, x1, x2, w;
    ofstream fout("pathsg.out");
    ifstream fin("pathsg.in");
    fin>>n>>m;
    vector < vector < pair<long long,long long> > > graph (n, vector < pair<long long, long long>> () );
    for (size_t i = 0; i < m; ++i) {
        fin >> x1 >> x2 >> w;
        graph[x1-1].push_back(make_pair(x2-1, w));
    }
    vector<long long> result(n);
    for (size_t i = 0; i < n; i++){
        result = way(graph, i, n);
        for (size_t j = 0; j < result.size(); j++)
            fout<<result[j]<<' ';
        fout<<endl;
    }
    fout.close();
    fin.close();
    return 0;
}
