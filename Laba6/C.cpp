#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Tree {
public:
    struct Node {
        int value;
        Node *left = nullptr;
        Node *right = nullptr;

        Node(int value) : value{value}, left{nullptr}, right{nullptr} {}
    };

    Node *root = nullptr;


    int next(Node *New_Node, int key, Node *result) {
        if (New_Node == nullptr)
            return result->value;

        if (New_Node->value <= key) {
            next(New_Node->right, key, result);
        } else {
            result->value = New_Node->value;
            next(New_Node->left, key, result);
        }

        return (result->value);
    }

    int prev(Node *New_Node, int key, Node *result) {
        if (New_Node == nullptr)
            return result->value;

        if (New_Node->value >= key) {
            prev(New_Node->left, key, result);
        } else {
            result->value = New_Node->value;
            prev(New_Node->right, key, result);
        }

        return (result->value);
    }


    string exists(int key) {
        if(this->root == nullptr)
            return "false";

        Node* New_Node = this->root;
        while (New_Node != nullptr){
            if(New_Node->value == key)
                return "true";
            if(key < New_Node->value)
                New_Node = New_Node->left;
            else
                New_Node = New_Node->right;
        }
        return "false";
    }


    void insert(int key) {
        Node *New_Node = this->root;
        if (New_Node == nullptr) {
            this->root = new Node(key);
        } else {
            while (true) {
                if (New_Node->value == key) return;
                if (key < New_Node->value) {
                    if (New_Node->left == nullptr) {
                        New_Node->left = new Node(key);
                        return;
                    } else
                        New_Node = New_Node->left;
                } else {
                    if (New_Node->right == nullptr) {
                        New_Node->right = new Node(key);
                        return;
                    } else
                        New_Node = New_Node->right;
                }
            }
        }
    }

    void remove(int key) {
        if(this->root == nullptr)
            return;
        Node *New_Node = root, *parent = nullptr;
        while (New_Node != nullptr){
            if(New_Node->value == key)
                break;
            parent = New_Node;
            if(key < New_Node->value)
                New_Node = New_Node->left;
            else
                New_Node = New_Node->right;
        }
        if(New_Node == nullptr)
            return;

        if(New_Node->right == nullptr){
            if(parent == nullptr)
                root = New_Node->left;
            else
            if(New_Node == parent->left)
                parent->left = New_Node->left;
            else
                parent->right = New_Node->left;
        } else {
            Node *mostLeft = New_Node->right;
            parent = nullptr;
            while (mostLeft->left != nullptr) {
                parent = mostLeft;
                mostLeft = mostLeft->left;
            }

            if(parent != nullptr)
                parent->left = mostLeft->right;
            else
                New_Node->right = mostLeft->right;

            New_Node->value = mostLeft->value;
        }
    }

};

int main() {
    ifstream fin("bstsimple.in");
    ofstream fout("bstsimple.out");
    Tree Wood;
    string comm;
    int key, x;
    while (fin >> comm >> key) {
        if (comm == "insert") {
            Wood.insert(key);
        } else if (comm == "delete") {
            Wood.remove(key);
        } else if (comm == "exists") {
            auto res = Wood.exists(key);
                fout << res << endl;
        } else if (comm == "next") {
            auto result = new Tree::Node(key);
            int m = Wood.next(Wood.root, key, result);
            if (m != key) {
                fout << m << endl;
            } else {
                fout << "none" << endl;
            }

        } else if (comm == "prev") {
            auto result = new Tree::Node(key);
            int m = Wood.prev(Wood.root, key, result);
            if (m != key) {
                fout << m << endl;
            } else {
                fout << "none" << endl;
            }
        }
    }

}