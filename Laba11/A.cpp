#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;
int main() {
    long long n, start, finish, x;
    const long long INF = 9223372036854775806;
    ofstream fout("pathmgep.out");
    ifstream fin("pathmgep.in");
    fin>>n>>start>>finish;
    vector < vector < pair<long long,long long> > > g (n);
    long long s = start - 1;
    for ( long long i = 0; i < n; ++i)
        for(long long j = 0 ; j < n; ++j) {
            fin >> x;
            if (x != -1)
                g[i].push_back(make_pair(j, x));
        }
    vector<long long> d (n, INF),  p (n);
    d[s] = 0;
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
    if ( d[finish-1] == INF)
        fout<<-1;
    else
        fout<<d[finish-1];
    fout.close();
    fin.close();
    return 0;
}
