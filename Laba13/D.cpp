#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
string sample;
int my_size;
vector<vector<int>> delta;

void Read() {
    cin >> my_size >> sample;
    sample += "  ";
    delta.resize(sample.length() - 1);
    for (int i = 0; i < delta.size(); i++)
        delta[i].resize(my_size, 0);
}

vector<int> prefix(const string &s) {
    vector<int> p;
    p.resize(s.length(), 0);
    p[0] = 0;
    for (int i = 1; i < s.length(); i++)
    {
        int k = p[i - 1];
        while ((k > 0) && (s[i] != s[k]))
            k = p[k - 1];
        if (s[i] == s[k])
            k++;
        p[i] = k;
    }
    return p;
}

void makeKMP(vector<int>& pref)
{
    for (int q = 0; q < sample.length() - 1; q++)
        for (int a = 0; a < my_size; a++)
            if (q == 0)
                if (a == sample.at(q) - 'a')
                    delta[q][a] = q + 1;
                else
                    delta[q][a] = q;
            else
                if ((a != sample.at(q) - 'a'))
                {
                    delta[q][a] = delta[pref[q - 1]][a];
                    continue;
                }
                else
                    delta[q][a] = q + 1;
}

int main()
{
    Read();
    vector<int> result;
    result = prefix(sample);
    makeKMP(result);
    for (int i = 0; i < delta.size(); i++)
    {
        for (int j = 0; j < delta[i].size(); j++)
            std::cout << delta[i][j] << " ";
        std::cout << '\n';
    }
    return 0;
}