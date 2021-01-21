#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int n = 100000;

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

struct Node {
    string value;
    string key;
    Node *nextkey =nullptr;
    Node *prevkey =nullptr;
    Node *Next = nullptr;
};

class Linked_list {
public:
    Node *Head = new Node{};
    int length = 0;

    Node* push(string k, string val, Node* last,Node* n  ) {
        Node *elem = Head;
        while (elem != nullptr) {
            if (elem->key == k) {
                elem->value = val;
                return last;
            }
            elem = elem->Next;
        }
        Node *a = new Node{};
        a->key = k;
        a->value = val;
        a->prevkey=last;
        a->nextkey=n;
        n->prevkey=a;
        a->Next = Head->Next;
        Head->Next = a;
        last->nextkey=Head->Next;
        length++;
        return Head->Next;
    }

    Node* pop(string k) {

        Node *elem = Head;
        Node *el = new Node{};
        while (elem->Next != nullptr) {
            if (elem->Next->key == k) {
                elem->Next->prevkey->nextkey=elem->Next->nextkey;
                elem->Next->nextkey->prevkey=elem->Next->prevkey;
                el=elem->Next;
                elem->Next = elem->Next->Next;
                break;
            }
            elem = elem->Next;
        }
        return el;

    }

    Node* find(string k) {
        Node *elem = Head->Next;
        while (elem != nullptr) {
            if (elem->key == k) {
                return elem;
            }
            elem = elem->Next;
        }
        return elem;
    }


};


int main() {

    ifstream fin("linkedmap.in");
    ofstream fout("linkedmap.out");

    string str, str1, str2;
    vector<Linked_list> array(n);
    Node* last=new Node{};
    Node*n=new Node{};

    while (fin.eof() != 1) {
        fin >> str;
        if (str == "put") {
            fin >> str1;
            fin >> str2;
            int k = fun(str1);
            Node* l=array[k].push(str1,str2,last,n);
            if(l->key.length()!=0){
                last=l;
            }

        }
        if (str == "delete") {
            fin >> str1;
            int k = fun(str1);
            Node* l=array[k].pop(str1);
            if(l==last){
                last=l->prevkey;
            }

        }
        if (str == "get") {
            fin >> str1;
            int k = fun(str1);
            Node *l=array[k].find(str1);
            if(l!= nullptr)
                fout<<l->value<<"\n";
            else
                fout<<"none"<<"\n";
        }
        if (str == "prev") {
            fin >> str1;
            int k=fun(str1);
            Node *l=array[k].find(str1);
            if(l!= nullptr)
                if(l->prevkey!= nullptr&& l->prevkey->key.length()!=0)
                    fout<<l->prevkey->value<<"\n";
                else
                    fout<<"none"<<"\n";
            else
                fout<<"none"<<"\n";
        }
        if (str == "next") {
            fin >> str1;
            int k=fun(str1);
            Node *l=array[k].find(str1);
            if(l!= nullptr)
                if(l->nextkey!= nullptr && l->nextkey->key.length()!=0)
                    fout<<l->nextkey->value<<"\n";
                else
                    fout<<"none"<<"\n";
            else
                fout<<"none"<<"\n";

        }
        str = " ";
    }


    fin.close();
    fout.close();
    return 0;
}