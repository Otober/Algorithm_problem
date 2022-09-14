#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 500005;

int group[N] = {};

queue < pair < int, int > > q;

void f_initialize() {
	for (int i = 0; i < N; i++) {
		group[i] = i;
	}
}

int f_find(int node) {
	while (group[node] != node) {
		node = group[node];
	}
	return node;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	f_initialize();
	bool flag = false;
	int n, m;
	int cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		q.push(make_pair(a, b));
	}

	while (!q.empty()) {
		cnt++;
		int a, b;
		a = q.front().first;
		b = q.front().second;
		q.pop();
		int ga = f_find(a);
		int gb = f_find(b);
		if (ga == gb) {
			cout << cnt;
			flag = true;
			break;
		}
		if (ga > gb) swap(ga, gb);
		group[gb] = ga;
	}
	if (flag == false) cout << 0;
	return 0;
}