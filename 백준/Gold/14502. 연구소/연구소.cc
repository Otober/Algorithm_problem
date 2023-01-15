#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 9;

const int dy[4] = { 0,1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

int n, m;
int answer = 0;

bool visit[N][N] = {};

int arr[N][N] = {};

vector < pair < int, int > > v;

queue < pair < int, int > > q;

bool f_check(int y, int x) {
	if (y < 0 || y >= n) return false;
	if (x < 0 || x >= m) return false;
	if (visit[y][x] == true) return false;
	if (arr[y][x] == 1) return false;
	return true;
}

void f_bfs() {
	while (!q.empty()) {
		q.pop();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = false;
		}
	}

	for (int i = 0; i < v.size(); i++) {
		q.push(make_pair(v[i].first, v[i].second));
		visit[v[i].first][v[i].second] = true;
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (f_check(ny, nx)) {
				visit[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == false && arr[i][j] == 0) cnt++;
		}
	}
	if (answer < cnt) answer = cnt;
	return;
}


void f_simulator(int start, int cnt) {
	if (cnt == 3) {
		f_bfs();
		return;
	}

	for (int i = start + 1; i < n * m; i++) {
		int y = i / m;
		int x = i % m;
		if (arr[y][x] == 0) {
			arr[y][x] = 1;
			f_simulator(i, cnt + 1);
			arr[y][x] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				v.push_back(make_pair(i, j));
			}
		}
	}
	f_simulator(-1, 0);
	cout << answer;
	return 0;
}