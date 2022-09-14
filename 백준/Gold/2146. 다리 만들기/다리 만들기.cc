#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 105;
const int INF = 987654321;

const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

int n;
int cnt = 0;
int ans = INF;

int map[N][N] = {};
int visit[N][N] = {};

bool f_check(int y, int x) {
	if (y < 0 || y >= n) return false;
	if (x < 0 || x >= n) return false;
	if (map[y][x] == 0) return false;
	if (visit[y][x] != 0) return false;
	return true;
}

bool f_check(int y, int x, int island) {
	if (y < 0 || y >= n) return false;
	if (x < 0 || x >= n) return false;
	if (visit[y][x] == island) return false;
	return true;
}

void f_dfs(int y, int x) {
	visit[y][x] = cnt;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (f_check(ny, nx)) f_dfs(ny, nx);
	}
}

void f_bfs(int island) {
	queue < pair < int, int > > q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == island) {
				q.push(make_pair(i, j));
				visit[i][j] = 0;
			}
		}
	}

	int result = 0;
	while (!q.empty()) {
		int q_size = q.size();
		result++;
		for (int k = 0; k < q_size; k++) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (f_check(ny, nx, island)) {
					if (visit[ny][nx] > visit[y][x] + 1) {
						visit[ny][nx] = visit[y][x] + 1;
						q.push(make_pair(ny, nx));
					}
					if (map[ny][nx] != 0 && map[ny][nx] != island) {
						ans = min(ans, result);
						return;
					}
				}
			}
		}
	}
}

void f_initialize() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = INF;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && visit[i][j] == 0) {
				cnt++;
				f_dfs(i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = visit[i][j];
		}
	}

	for (int k = 1; k <= cnt; k++) {
		f_initialize();
		f_bfs(k);
	}
	cout << ans - 1;
	return 0;
}