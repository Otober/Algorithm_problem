#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool comp(const pair<int, int> &p1, const pair<int, int> &p2)
{
	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}
	return p1.second > p2.second;
}

int main()
{
	int n;
	double sum = 0;
	vector < int >adj;
	vector <pair<int, int> >v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		sum += temp;
		adj.push_back(temp);
	}
	sort(adj.begin(), adj.end());
	
	for (int i = 0; i < adj.size(); i++) {
		if (v.empty()) {
			v.push_back(make_pair(adj[i], 1));
			continue;
		}
		if (v.back().first == adj[i]) {
			int tmp = v.back().second + 1;
			v.pop_back();
			v.push_back(make_pair(adj[i], tmp));
		}
		else v.push_back(make_pair(adj[i], 1));
	}
	sort(v.begin(), v.end(), comp);
	cout << (int)floor(sum / n + 0.5) << endl;
	cout << adj[n / 2] << endl;
	if (n == 1 || v[0].second != v[1].second) {
		cout << v[0].first << endl;
	}
	else {
		cout << v[1].first << endl;
	}
	cout << adj[n - 1] - adj[0] << endl;
	return 0;
}