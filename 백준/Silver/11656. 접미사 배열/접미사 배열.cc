#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
	string s;
	cin >> s;
	int ss = s.size();
	vector <int> a;
	for (int i = 0; i < ss; i++)a.push_back(i);
	sort(a.begin(), a.end(), [&s](int u, int v) {return strcmp(s.c_str() + u, s.c_str() + v) < 0; });
	for (auto&x : a) { cout << s.substr(x) << '\n'; }
}