#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>

using namespace std;


class Set {
private:
    vector<list<int>> hashTable;

    unsigned hash(int key) {
        return key % hashTable.size();
    }

public:
    Set() : Set (1000003) {}

    Set(unsigned size) {
        hashTable.resize(size);
    }

    bool exists(int key) {
        unsigned index = hash(key);
        for (int i : hashTable[index]) {
            if (i == key)
                return true;
        }
        return false;
    }

    void insert(int key) {
        if (exists(key) != true)
            hashTable[hash(key)].push_back(key);
    }

    void remove(int key) {
        unsigned index = hash(key);
        for (auto i = hashTable[index].begin(); i != hashTable[index].end(); i++) {
            if (*i == key) {
                hashTable[index].erase(i);
                return;
            }
        }
    }

    void clear() {
        hashTable.clear();
    }

};

int main() {
    Set set(1000003);
    ifstream filein("set.in");
    ofstream fileout("set.out");
    string command;
    int key;
    while (!filein.eof()) {
        command = "";
        filein >> command;
        filein >> key;
        if (command == "insert") {
            set.insert(key);
        }
        else if (command == "delete") {
            set.remove(key);
        }
        else if (command == "exists") {
            if (set.exists(key))
                fileout << "true\n";
            else
                fileout << "false\n";
        }
    }
    filein.close();
    fileout.close();
}