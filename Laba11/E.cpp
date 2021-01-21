#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <fstream>

using namespace std;

struct vertex{
    long long from, to, weight;
};
const long long INF = INT_MAX;

int main(){
    long long n;
    ifstream fin("negcycle.in");
    ofstream fout("negcycle.out");
    fin >> n;
    long long x;
    vector <vertex> graph;
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < n; j++){
            fin >> x;
            graph.push_back({i,j,x});
        }
    }
    vector<long long> d(n, INF), p(n, -1);
    d[0] = 0;
    for(long long i = 0; i < n; i++){
        x = -1;
        for(long long j = 0; j < graph.size(); j++){
            long long from = graph[j].from;
            long long to = graph[j].to;
            long long weight = graph[j].weight;
            if(d[to] > d[from] + weight ){
                d[to] = max(d[from] + weight, -INF);
                p[to] = from;
                x = to;
            }
        }
    }
    if(x == -1){
        cout << "NO" << endl;
    }else{
        long long y = x;
        for(long long i = 0; i < n; i++){
            y = p[y];
        }
        vector <long long> path;
        for(long long cur = y;; cur = p[cur]){
            path.push_back(cur);
            if(cur == y && path.size() > 1){
                break;
            }
        }
        reverse(path.begin(), path.end());
        fout << "YES" << endl;
        fout << path.size() << endl;
        for(long long i = 0; i < path.size(); i++){
            fout << path[i] + 1;
            if(i != path.size()-1){
                fout << ' ';
            }
        }
        fout << endl;
    }
    return 0;
}