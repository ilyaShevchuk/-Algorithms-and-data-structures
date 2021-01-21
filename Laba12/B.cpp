#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
bool Kun(vector<vector<int>> &graph,vector<char> &used,vector<int> &maximal_pairs, int v){
    if (used[v])
        return false;
    used[v] = true;
    for (int i = 0; i < graph[v].size();i++){
        int to = graph[v][i];
        if (maximal_pairs[to] == -1 || Kun(graph, used, maximal_pairs, maximal_pairs[to])){
            maximal_pairs[to] = v;
            return true;
        }
    }
    return false;
}


int main() {
    int n, k, m;
    ifstream fin("matching.in");
    ofstream fout("matching.out");
    fin>>n>>m>>k;
    vector<int> maxi_pairs(m, -1);
    vector<char> use(n, false);
    vector<char> used1(n);
    vector<vector<int>> g;
    g.resize(n, vector<int>() );

    int a, b;
    for(int i = 0; i < k; ++i){
        fin>>a>>b;
        g[a-1].push_back(b-1);
    }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < g[i].size(); j++)
            if (maxi_pairs[g[i][j]] == -1){
                maxi_pairs[g[i][j]] = i;
                used1[i] = true;
                break;
            }
    for(int i = 0; i < n; i++){
        if (used1[i]) continue;
        use.assign(n, false);
        Kun(g, use, maxi_pairs, i);
    }

    int count = 0;
    for(int i = 0; i < m; i++){
        if (maxi_pairs[i] != -1)
            count+=1;
    }
    fout<<count;
    return 0;
}
