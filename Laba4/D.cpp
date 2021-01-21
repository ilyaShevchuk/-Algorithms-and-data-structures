
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


struct stac
{
	int key;
	stac* next;
};


void push(stac** head, long long int D) {
	stac* q;
	q = new stac();
	q->key = D;
	if (head == NULL) {
		*head = q;
	}
	else {
		q->next = *head;
		*head = q;
	}
}


void key_delete(stac** head, int x) {
	stac* q = *head;
	stac* prev = NULL;
	while (q != NULL) {
		if (q->key == x) {
			if (q == *head) {
				*head = q->next;
				free(q);
				q->key = NULL;
				q->next = NULL;
			}
			else {
				prev->next = q->next;
				free(q);
				q->key = NULL;
				q->next = NULL;
			}
		}
		prev = q;
		q = q->next;
	}

}
int KEY(stac** head) {
	stac* q = *head;
	return q->key;
}


int KEY2(stac** head) {
	stac* q = *head;
	return q->next->key;
}


void last_delete(stac** head) {
	int value;
	stac* q = *head;
	*head = q->next;
	value = q->key;
	free(q);
	q->key = NULL;
	q->next = NULL;
}


void s_print(stac* top) {
	stac* q = top;
	while (q) {
		cout << q->key;
		q = q->next;
	}
}

int main() {
	stac* Head = NULL;
	ifstream fin("postfix.in");
	ofstream fout("postfix.out");
	// 57 - 48
	string s1;
	getline(fin, s1);
	int n = s1.length();
	for (int i =0;i<n;i+=2){
		char ch = s1[i];
		if ((ch >= 48) && (ch <= 57)) {
			int j = ch - 48;
			int i = 12;
			push(&Head, j);
		}
		else {
			if (ch == '+') {
				long long  int sum = KEY(&Head) + KEY2(&Head);
				last_delete(&Head);
				last_delete(&Head);
				push(&Head, sum);
			}
			if (ch == '*') {
				long long  int sum = KEY(&Head) * KEY2(&Head);
				last_delete(&Head);
				last_delete(&Head);
				push(&Head, sum);
			}
			if (ch == '-') {
				long long int sum = KEY2(&Head) - KEY(&Head);
				last_delete(&Head);
				last_delete(&Head);
				push(&Head, sum);
			}
		}
	}
	cout << KEY(&Head);
	fout << KEY(&Head);		
	fin.close();
	fout.close();
	return 0;
};
