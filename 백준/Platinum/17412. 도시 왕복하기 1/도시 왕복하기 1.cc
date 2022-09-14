#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 405;
const int INF = 987654321;

int c[N][N] = {};
int f[N][N] = {};

vector < int > v[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		c[a][b] = 1;
		//c[b][a] = 1;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int ans = 0;
	const int S = 1, T = 2;
	while (true) {
		int prev[N] = {};
		fill_n(prev, N, -1);
		queue < int > q;
		q.push(S);

		while (!q.empty()) {
			int node = q.front();
			q.pop();

			for (int next : v[node]) {
				if (prev[next] != -1) continue;

				if (c[node][next] - f[node][next] > 0) {
					q.push(next);
					prev[next] = node;
					if (next == T) break;
				}
			}
		}

		if (prev[T] == -1) break;

		int flow = INF;
		for (int i = T; i != S; i = prev[i]) {
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		}
		for (int i = T; i != S; i = prev[i]) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		ans += flow;
	}
	cout << ans;
	return 0;
}