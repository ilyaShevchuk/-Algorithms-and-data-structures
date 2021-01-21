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



bool check(Node* a, int min ,int max ){
    if(a == nullptr)
        return true;
    if ((a->value <= min)||(a->value >= max))
        return false;
    return (check(a->Left,min,a->value)&&check(a->Right,a->value,max));

}

int main() {

    ifstream fin("check.in");
    ofstream fout("check.out");

    int n;
    fin >> n;

    Node a[n+2];


    int max = 1000000001;
    int min = -1000000001;



    for(int i=1;i<=n;i++){
        long f,l,r;
        fin >> f >> l >> r;
        a[i].value = f;

        if (l!=0)
            a[i].Left=&a[l];
        if (r!=0)
            a[i].Right=&a[r];
    }




    bool flag=check(&a[1],min,max);

    if (flag == true)
        fout<<"YES";
    else
        fout<<"NO";
    fin.close();
    fout.close();

    return 0;
}