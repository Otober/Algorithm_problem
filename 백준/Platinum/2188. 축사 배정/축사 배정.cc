#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 205;

bool visit[N] = {};

int arr[N] = {};

vector < int > v[N];

bool f_dfs(int node) {
	for (int next : v[node]) {
		if (visit[next]) continue;
		visit[next] = true;
		if (arr[next] == 0 || f_dfs(arr[next])) {
			arr[next] = node;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int temp;
			cin >> temp;
			v[i].push_back(temp);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		fill_n(visit, N, false);
		if (f_dfs(i)) ans++;
	}
	cout << ans;
	return 0;
}