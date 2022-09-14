#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 15;
const int INF = 987654321;

const int dy[4] = { 1, 0, -1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

int n, m;
int ans = 0;
int cnt = 0;

int tcnt[N] = {};
int group[N] = {};

int arr[N][N] = {};
int map[N][N] = {};
int visit[N][N] = {};


priority_queue < pair < int, pair < int, int > > > pq;

int f_group(int node) {
	while (group[node] != node) {
		node = group[node];
	}
	return node;
}

bool f_check(int y, int x) {
	if (y < 0 || y >= n) return false;
	if (x < 0 || x >= m) return false;
	if (map[y][x] == 0) return false;
	if (visit[y][x] != 0) return false;
	return true;
}

bool f_check(int y, int x, int island) {
	if (y < 0 || y >= n) return false;
	if (x < 0 || x >= m) return false;
	if (map[y][x] == island) return false;
	return true;
}

void f_dfs(int y, int x) {
	visit[y][x] = cnt;
	for (int k = 0; k < 4; k++) {
		int ny = y + dy[k];
		int nx = x + dx[k];
		if (f_check(ny, nx)) f_dfs(ny, nx);
	}
}

void f_bfs(int island) {
	queue < pair < int, int > > q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == island) {
				visit[i][j] = 0;
				q.push(make_pair(i, j));
			}
		}
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = y;
			int nx = x;
			int cnt = 0;
			while (true) {
				cnt++;
				ny += dy[k];
				nx += dx[k];
				if (f_check(ny, nx, island)) {
					if (map[ny][nx] != 0 && map[ny][nx] != island) {
						if (cnt >= 3) {
							arr[island][map[ny][nx]] = min(arr[island][map[ny][nx]], cnt - 1);
						}
						break;
					}
				}
				else break;
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

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && visit[i][j] == 0) {
				cnt++;
				f_dfs(i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = visit[i][j];
		}
	}

	for (int i = 1; i <= cnt; i++) {
		for (int j = 1; j <= cnt; j++) {
			arr[i][j] = INF;
		}
		arr[i][i] = 0;
	}

	for (int i = 1; i <= cnt; i++) {
		f_initialize();
		f_bfs(i);
	}

	for (int i = 1; i <= cnt; i++) {
		for (int j = i + 1; j <= cnt; j++) {
			if (arr[i][j] != INF) pq.push(make_pair(-arr[i][j], make_pair(i, j)));
		}
	}

	for (int i = 1; i <= cnt; i++) {
		tcnt[i] = 1;
		group[i] = i;
	}
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		pq.pop();

		int ga = f_group(a);
		int gb = f_group(b);

		if (ga > gb) swap(ga, gb);
		if (ga != gb) {
			ans += dist;
			group[gb] = ga;
			tcnt[ga] += tcnt[gb];
		}
	}
	if (tcnt[1] == cnt) cout << ans;
	else cout << -1;
	return 0;
}