#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
int main() {
    ifstream fin("spantree3.in");
    ofstream fout("spantree3.out");


    long long n, m;
    fin >> n >> m;

    vector<bool> visited(n, false);
    vector<vector<pair<long long, long long>>> arr(n);

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> q;

    long long a, b, c;
    for (long long i = 0; i < m; i++) {
        fin >> a >> b >> c;
        arr[a - 1].push_back({c, b - 1});
        arr[b - 1].push_back({c, a - 1});

    }

    long long weight = 0;

    q.push({0, 0});

    while (!q.empty()) {
        pair<long long, long long> e = q.top();
        q.pop();

        if (visited[e.second]) continue;

        visited[e.second] = true;
        weight += e.first;

        for (pair<long long, long long> u : arr[e.second]) {
            if (!visited[u.second])
                q.push(u);
        }
    }
    fout << weight;
    fin.close();
    fout.close();
    return 0;
}