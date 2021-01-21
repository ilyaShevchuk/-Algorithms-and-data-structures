#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node{
    int value;
    Node* Left= nullptr;
    Node* Right= nullptr;
};

int height(Node a){
    if (a.Left== nullptr )
        return 0;
    else
        return 1+max(height(*a.Left),height(*a.Right));
}

int main() {

    ifstream fin("height.in");
    ofstream fout("height.out");

    int n;
    fin>>n;

    Node a[n];

    for(int i=1;i<n+1;i++){
        int f,l,r;
        fin>>f>>l>>r;
        a[i].value=f;
        a[i].Left=&a[l];
        a[i].Right=&a[r];
    }

    fout<<(height(a[1]));

    fin.close();
    fout.close();

    return 0;
}