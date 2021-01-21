#include <iostream>
#include <fstream>

using namespace std;

struct Node {
	char value;
	Node* Next = nullptr;
};

class Linked_list {
public:
	Node* Head = new Node{};
	int length = 0;

	void push(const char& element) {
		Node* a = new Node{};
		a->value = element;
		a->Next = Head->Next;
		Head->Next = a;
		length++;
	}

	char pop() {
		Node* elem = Head->Next;
		if (Head->Next->Next != nullptr) {
			Head->Next = Head->Next->Next;
			length--;
		}
		else {
			Head->Next = nullptr;
			length = 0;
		}

		return elem->value;

	}
	void free() {
		Head->Next = nullptr;
		length = 0;
	}



	int size() {
		return length;
	}
};

int main() {

	Linked_list a;
	ifstream fin("brackets.in");
	ofstream fout("brackets.out");
	char  c, c1;
	string answer, str1;
	int i;
	while (fin.eof() != 1) {

		i = 0;

		getline(fin, str1);
		answer = "YES";
		while (i < str1.size()) {
			c = str1[i];

			if (c == '(' || c == '[') {
				a.push(c);
			}
			else {
				if (a.size() == 0) {
					answer = "NO";
					i++;
					break;
				}
				else {
					c1 = a.pop();
					if ((c1 == '(' && c != ')') || (c1 == '[' && c != ']')) {
						answer = "NO";
						break;
					}
				}
			}
			i++;
		}
		if (a.size() != 0) {
			answer = "NO";
		}
		if (i != 0) {
			fout << answer << "\n";
		}
		a.free();
	}

	fin.close();
	fout.close();
	return 0;
};