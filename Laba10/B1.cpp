#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

struct point {
    int x, y;
};


void sptree(int v, int n, int &count, std::vector<point> &koo, std::vector<double> &ver, double &l,
            std::vector<bool> &visited) {


    for (int i = 0; i < n; i++) {
        double r = sqrt(pow(koo[v].x - koo[i].x, 2) + pow(koo[v].y - koo[i].y, 2));
        if (ver[i] == -1 || r < ver[i])
            ver[i] = r;
    }
    visited[v] = true;
    count++;

    if (count == n)
        return;


    int min = -1;
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;
        if (min == -1 || ver[i] < ver[min])
            min = i;
    }

    l += ver[min];
    sptree(min, n, count, koo, ver, l, visited);


}


int main() {

    std::ifstream fin("spantree.in");
    std::ofstream fout("spantree.out");
    fout.precision(20);


    int n;
    fin >> n;
    std::vector<point> koo(n);
    std::vector<double> ver(n, -1);
    std::vector<bool> visited(n, false);


    int x, y;
    for (int i = 0; i < n; i++) {
        fin >> x >> y;
        koo[i].x = x;
        koo[i].y = y;
    }


    double l = 0;
    int count = 0;


    sptree(0, n, count, koo, ver, l, visited);

    fout << l;


    fin.close();
    fout.close();


    return 0;
}
