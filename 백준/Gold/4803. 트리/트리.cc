#include <iostream>
#include <vector>

using namespace std;

const int N = 505;

bool visit[N] = {};

vector < int > v[N];

void f_initialize() {
	fill_n(visit, N, false);
	for (int i = 0; i < N; i++) {
		v[i].clear();
	}
}

bool f_dfs(int node, int before) {
	visit[node] = true;
	for (int next : v[node]) {
		if (next == before) continue;
		if (visit[next]) return false;
		if (f_dfs(next, node) == false) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    
	int t = 0;
	while(true) {
		f_initialize();
		t++;
		int n, m;
		int ans = 0;
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		for (int i = 1; i <= n; i++) {
			if (!visit[i]) {
				if (f_dfs(i, 0)) ans++;
			}
		}
		cout << "Case " << t << ": ";
		if (ans == 0) cout << "No trees.";
		else if (ans == 1) cout << "There is one tree.";
		else cout << "A forest of " << ans << " trees.";
		cout << "\n";
	}
	return 0;
}