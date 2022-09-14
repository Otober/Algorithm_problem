#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 105;
const int INF = 987654321;

int n, m;

int arr[N][N] = {};

vector < int > v[N][N];

void f_initialize() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = INF;
			v[i][j].clear();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	f_initialize();
	for (int i = 0; i < m; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		s--, e--;
		if (arr[s][e] > c) {
			arr[s][e] = c;
			v[s][e].clear();
			v[s][e].push_back(s + 1);
			v[s][e].push_back(e + 1);
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
					v[i][j].clear();
					v[i][j].insert(v[i][j].end(), v[i][k].begin(), v[i][k].end());
					v[i][j].insert(v[i][j].end(), v[k][j].begin() + 1, v[k][j].end());
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == INF) cout << 0 << " ";
			else cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j].size() << " ";
			for (int k = 0; k < v[i][j].size(); k++) {
				cout << v[i][j][k] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}