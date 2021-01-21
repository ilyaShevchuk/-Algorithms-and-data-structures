#include <iostream>
#include <fstream>
using namespace std;

struct Node {
	int value;
	int num;
	Node* Next = nullptr;
};

class Linked_list {
public:
	Node* Head = new Node{};
	int length = 0;
	int count = 1;

	int size() {
		return length;
	}

	void len() {
		count += 1;
	}

	void push(const int& element) {

		Node* a = new Node{};
		a->value = element;
		int b = count;
		a->num = count;
		a->Next = Head->Next;
		Head->Next = a;
		length++;
		count++;
	}

	void find(const int& target, const int& a) {
		Node* elem = Head->Next;
		while (elem->num != target) {
			elem = elem->Next;
		}
		elem->value = a;
		count++;
	}


	int popmin() {
		int min = Head->Next->value;
		Node* elem = Head;
		Node* last = Head;
		int n = length;
		while (n > 0) {
			if (elem->Next->value < min) {
				min = elem->Next->value;
				last = elem;
			}
			elem = elem->Next;
			n--;
		}

		last->Next = last->Next->Next;
		length--;
		count++;
		return min;
	}


};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ifstream fin("priorityqueue.in");
	ofstream fout("priorityqueue.out");
	Linked_list list;

	int value, num;
	string str;
	while (fin.eof() != 1) {
		fin >> str;
		if (str == "push") {
			fin >> value;
			list.push(value);
		}
		if (str == "extract-min") {
			if (list.size() != 0) {
				fout << list.popmin() << "\n";
			}
			else {
				fout << '*' << "\n";
				list.len();
			}
		}
		if (str == "decrease-key") {
			fin >> num;
			fin >> value;
			list.find(num, value);
		}
		str = "0";
	}

	fin.close();
	fout.close();
	return 0;
}