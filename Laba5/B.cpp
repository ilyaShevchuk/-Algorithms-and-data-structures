#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>

using namespace std;


class Map {
private:
    struct Unit{
        string key;
        string value;
    };


    vector<list<Unit>> hashTable;

    int hashing(string str){
        const int p = 31;
        int hash = 0, p_pow = 1;
        unsigned n = 100003;
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

public:

    Map() : Map (100003) {}

    Map(unsigned size) {
        hashTable.resize(size);
    }

    string get(string key) {
        unsigned index = hashing(key);
        for (Unit i : hashTable[index]){
            if (i.key == key){
                return i.value;
            }
        }
        return "none";
    }

    void put(string key, string value) {
        unsigned index = hashing(key);
        for (Unit& i : hashTable[index]) {
            if (i.key == key) {
                i.value = value;
                return;
            }
        }
        Unit NewElement;
        NewElement.key = key;
        NewElement.value = value;
        hashTable[index].push_back(NewElement);
    }

    void remove(string key) {
        unsigned index = hashing(key);
        for (auto i = hashTable[index].begin(); i != hashTable[index].end(); i++) {
            if (i->key == key) {
                hashTable[index].erase(i);
                return;
            }
        }
    }
};

int main() {
    Map map(100003);
    ifstream filein("map.in");
    ofstream fileout("map.out");
    string command, main_key, main_value;
    while (!filein.eof()) {
        command = "";
        filein >> command >> main_key;
        if (command == "put") {
            filein >> main_value;
            map.put(main_key, main_value);
        }
        else if (command == "delete") {
            map.remove(main_key);
        }
        else if (command == "get") {
            fileout << map.get(main_key) << '\n';
        }
    }
    filein.close();
    fileout.close();

}