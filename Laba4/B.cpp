#include <iostream>
#include <fstream>
using namespace std;
struct Node {
	int key;
	Node* Next;
};

class queue {
Node* Head;
Node* Leg;
public:
	queue() { Head = nullptr; Leg = nullptr; }
	void push(int x);
	void print();
	int first_delete();
};

void queue::push(int x) {
	Node* q = new Node;
	q->key = x;
	if (Leg == nullptr) {
		Leg = q;
	}
	q->Next = Head;
	Head = q;
}

void queue::print() {
	Node* q = Head;

	while (q != nullptr) {
		cout << q->key << ' ';
		q = q->Next;
	}
}

int queue::first_delete() {
	int z;
	Node* q = Head;
	if (Head == Leg) {
		Leg = nullptr;
		return q->key;
	}
	while (q->Next != Leg) {
		q = q->Next;
	}
	z = Leg->key;
	Leg = q;
	q = q->Next;
	free(q);
	return z;
}


int main()
{
	ifstream fin("queue.in");
	ofstream fout("queue.out");
	int y, res, n, cnt;
	queue Q;
	char ch;
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> ch;
		if (ch == '+') {
			fin >> y;
			Q.push(y);
		}
		else {
			res = Q.first_delete();
			fout << res<< '\n';
		}
	}
	return 0;
}
