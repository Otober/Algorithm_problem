#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 52;
const int INF = 987654321;

int c[N][N] = {};
int f[N][N] = {};

vector < int > v[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		char from_char, to_char;
		int val;
		cin >> from_char >> to_char >> val;

		int from, to;
		if ('A' <= from_char && from_char <= 'Z')  from = from_char - 'A';
		else from = from_char - 'a' + 26;
		if ('A' <= to_char && to_char <= 'Z')  to = to_char - 'A';
		else to = to_char - 'a' + 26;

		c[from][to] += val;
		c[to][from] += val;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	int totalFlow = 0, S = 0, T = 'Z' - 'A';
	while (true) {
		int prev[N];
		fill_n(prev, N, -1);
		queue < int > q;
		q.push(S);

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (int i = 0; i < v[now].size(); i++) {
				int next = v[now][i];
				if (prev[next] != -1) continue;

				if (c[now][next] - f[now][next] > 0) {
					q.push(next);
					prev[next] = now;
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
		totalFlow += flow;
	}
	cout << totalFlow;
	return 0;
}