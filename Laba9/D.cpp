#include <iostream>
#include<fstream>
#include <vector>

void dfs1(int v, std::vector<std::vector<int>> &G, std::vector<bool> &visited, std::vector<int> &ord) {
    visited[v] = true;
    for (int u: G[v])
        if (!visited[u])
            dfs1(u, G, visited, ord);
    ord.push_back(v);
}

void dfs2(int v, std::vector<std::vector<int>> &H, std::vector<bool> &used, std::vector<int> &comp) {
    used[v] = true;
    comp.push_back(v);
    for (int u: H[v])
        if (!used[u])
            dfs2(u, H, used, comp);
}


int main() {

    std::ifstream fin("cond.in");
    std::ofstream fout("cond.out");

    int n, m;
    fin >> n >> m;
    std::vector<std::vector<int>> G(n);

    std::vector<std::vector<int>> H(n);
    std::vector<bool> visited(n, false);
    std::vector<bool> used(n, false);
    std::vector<int> ord, comp;
    std::vector<int> cond(n);
    int a, b;
    for (int i = 0; i < m; i++) {
        fin >> a >> b;
        G[a - 1].push_back(b - 1);
        H[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < n; ++i)
        if (!visited[i])
            dfs1(i, G, visited, ord);

    int count = 1;
    for (int i = 0; i < n; i++) {
        int v = ord[n - 1 - i];
        if (!used[v]) {
            dfs2(v, H, used, comp);
            for (int i = 0; i < size(comp); i++)
                cond[comp[i]] = count;
            count++;
            comp.clear();
        }
    }

    fout << count - 1 << std::endl;
    for (int i = 0; i < n; i++) {
        fout << cond[i] << " ";
    }


    fin.close();
    fout.close();


    return 0;
}
