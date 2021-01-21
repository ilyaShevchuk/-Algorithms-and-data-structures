#include <iostream>
#include <fstream>
using namespace std;
struct stac
{
	int key;
	stac *next;
};
void push(stac** head, int D) {
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


int last_delete(stac** head) {
	int value;
	stac* q = *head;
	*head = q->next;
	value = q->key;
	free(q);
	q->key = NULL;
	q->next = NULL;
	return value;
}


void s_print(stac* top) { 	
	stac* q = top; 
	while (q) { 
		printf_s("%i", q->key, '\n');
		q = q->next;
	}
}


int main()
{
	ifstream fin("stack.in");
	ofstream fout("stack.out");
	int n,z;
	fin >> n;
	stac* top = NULL;
	for (int i = 0; i < n; i++) {
		char ch;
		int j;
		z = 0;
		fin >> ch;
		if (ch == '+') {
			fin >> j;
			push(&top, j);
		}
		else {
			z = last_delete(&top);
			fout << z <<'\n';
		}
	}

	return 0;
}

