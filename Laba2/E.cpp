#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
int partition(vector<int>& mas, int left, int right) {
	if (left != right)
		swap(mas[rand() % (right - left)+left], mas[right]);
	int x = mas[right];
	int i = left - 1;
	for (int j = left; j <= right; j++) {
		if (mas[j] <= x)
			swap(mas[++i], mas[j]);
	}
	return i;
}
int find(vector<int> mas, int n) {
	int left = 0, right = mas.size() - 1;
	for (;;) {
		int pos = partition(mas, left, right);
		if (pos < n)
			left = pos + 1;
		else if (pos > n)
			right = pos - 1;
		else return mas[n];
	}
}
int main()
{
	int k, n,A,B,C,a1,a2,res;
	ifstream fin("kth.in");
	ofstream fout("kth.out");
	fin >> n >> k;
	fin >> A >> B >> C >> a1 >> a2;
	vector<int> masiv(n);
	masiv[0] = a1;
	masiv[1] = a2;
	for (int i = 2;i < n;i++) {
		masiv[i] = A * masiv[i - 2] + B * masiv[i - 1] + C;
		}
	k -= 1;
	nth_element(masiv.begin(), masiv.begin() + k, masiv.end());
	fout <<masiv[k] ;
	fin.close();
	fout.close();

	return 0;
}
