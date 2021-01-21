#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int n=100;

ifstream fin("multimap.in");
ofstream fout("multimap.out");

int fun(string str){
    const int p = 31;
    int hash = 0, p_pow = 1;
    for (char i : str)
    {
        hash += (i - 'a' + 1) * p_pow;
        p_pow *= p;
    }
    if (hash >= 0) {
        return hash % n ;
    }
    else {
        return (n - abs(hash) % n) % n;
    }
}

struct Node2 {
    string key;
    Node2* Next = nullptr;

};


class set{
public:

    Node2 * Head2= new Node2{};
    int push2(string k) {


        Node2 *b = Head2;

        while(b!= nullptr){
            if(b->key==k){
                return 0;
            }
            b=b->Next;
        }
        Node2 *elem=new Node2{};
        elem->key=k;
        elem->Next=Head2->Next;
        Head2->Next=elem;
        return 1;

    }

    void print (){
        Node2* a =Head2->Next;
        while(a!= nullptr){
            fout<<a->key<<" ";
            a=a->Next;
        }


    }
    int pop2(string k){
        Node2*a=Head2;
        while(a->Next!= nullptr){
            if (a->Next->key==k){
                a->Next=a->Next->Next;
                return 1;
            }
            a=a->Next;

        }


        return 0;
    }


};


struct Node {
    string key;
    vector <set> array= vector <set>(n);
    Node* Next= nullptr;
    int length=0;
};



class Linked_list {
public:



    Node* Head = new Node{};


    void push(string k, string val) {
        Node*a=Head->Next;
        while(a!= nullptr){
            if(a->key==k){
                int k1=fun(val);
                int b= a->array[k1].push2(val);
                if(b==1)
                    a->length++;
                return;
            }
            a=a->Next;
        }
        Node* elem=new Node{};
        elem->key=k;
        int k1=fun(val);
        int b =elem->array[k1].push2(val);
        if(b==1)
            elem->length++;
        elem->Next=Head->Next;
        Head->Next=elem;
    }

    void pop(string k,string val) {
        Node *a=Head->Next;
        while(a!= nullptr){
            if(a->key==k){
                int k1=fun(val);
                int b=a->array[k1].pop2(val);
                if(b==1)
                    a->length--;
                return;
            }
            a=a->Next;
        }

    }

    void find(string k){
        Node* a=Head;
        while(a!=nullptr){
            if(a->key==k){
                fout<< a->length<<" ";
                if (a->length!=0){
                    for(int j=0;j<n;j++)
                        a->array[j].print();
                }
                fout<<"\n";

                return;
            }
            a=a->Next;
        }
        fout<<0<<"\n";
    }
    void deleteall(string k){
        Node*a=Head;
        while(a!= nullptr){
            if(a->key==k){
                if(a->length!=0){
                    a->array= vector<set>(n);
                    a->length=0;
                }
                return;
            }
            a=a->Next;

        }
    }


};


int main() {
    ifstream fin("multimap.in");
    ofstream fout("multimap.out");

    string str,str1,str2;
    vector<Linked_list> array(n);

    while(fin.eof()!=1){
        fin>>str;
        if(str=="put"){
            fin>>str1;
            fin>>str2;
            int k=fun(str1) ;
            array[k].push(str1,str2);
        }
        if (str=="delete"){
            fin>>str1;
            fin>>str2;
            int k=fun(str1);
            array[k].pop(str1,str2);
        }
        if (str=="get"){
            fin>>str1;
            int k=fun(str1);
            array[k].find(str1);
        }
        if (str=="deleteall"){
            fin>>str1;
            int k=fun(str1);
            array[k].deleteall(str1);
        }
        str=" ";
    }


    fin.close();
    fout.close();
    return 0;
}