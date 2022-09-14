#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 3005;

int n;

int cnt[N] = {};
int group[N] = {};

vector < pair < pair < long long, long long >, pair < long long, long long > > > v;

int f_ccw(pair < long long, long long > a, pair < long long, long long > b, pair < long long, long long > c) {
	long long temp = (a.first * b.second) + (b.first * c.second) + (c.first * a.second);
	temp -= (a.first * c.second) + (b.first * a.second) + (c.first * b.second);
	if (temp > 0) return -1;
	if (temp < 0) return 1;
	else return 0;
}

bool f_cross(pair < long long, long long > &a, pair < long long, long long >& b, pair < long long, long long >& c, pair < long long, long long >& d) {
	int abc = f_ccw(a, b, c);
	int abd = f_ccw(a, b, d);
	int cda = f_ccw(c, d, a);
	int cdb = f_ccw(c, d, b);
	if ((abc * abd == 0) && (cda * cdb == 0)) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		if (a <= d && c <= b) return true;
		else return false;
	}
	if ((abc * abd <= 0) && (cda * cdb <= 0)) return true;
	else return false;
}

int f_find(int node) {
	while (node != group[node]) {
		node = group[node];
	}
	return node;
}

void f_union(int a, int b) {
	a = f_find(a);
	b = f_find(b);
	if (a == b) return;
	if (a > b) swap(a, b);
	group[b] = a;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		v.push_back(make_pair(make_pair(a, b), make_pair(c, d)));
		group[i] = i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (f_cross(v[i].first, v[i].second, v[j].first, v[j].second)) f_union(i, j);
		}
	}

	int tcnt = 0, tmax = 0;
	for (int i = 0; i < n; i++) {
		if (group[i] == i) tcnt++;
		cnt[f_find(i)]++;
		tmax = max(tmax, cnt[f_find(i)]);
	}
	cout << tcnt << "\n";
	cout << tmax;
	return 0;
}