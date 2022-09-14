#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int N = 1005;
const int INF = 987654321;

int visit[N] = {};
int before[N] = {};

int t_v[N][N] = {};

vector < pair < int, int > > v[N];

stack < int > st;

priority_queue < pair < int, int > >pq;

void f_initialize() {
	fill_n(visit, N, INF);
	fill_n(before, N, -1);
	for (int i = 0; i < N; i++) {
		fill_n(t_v[i], N, INF);
	}
}

void f_backtracking(int node) {
	if (node == -1) return;
	st.push(node);
	f_backtracking(before[node]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	f_initialize();

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		t_v[a][b] = min(t_v[a][b], c);
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (t_v[i][j] != INF) {
				v[i].push_back(make_pair(j, t_v[i][j]));
			}
		}
	}

	int start, end;
	cin >> start >> end;

	pq.push(make_pair(-0, start));
	visit[start] = 0;

	while (!pq.empty()) {
		int ncost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (visit[now] < ncost) continue;

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int cost = v[now][i].second;
			if (visit[next] > visit[now] + cost) {
				visit[next] = visit[now] + cost;
				before[next] = now;
				pq.push(make_pair(-visit[next], next));
			}
		}
	}

	f_backtracking(end);
	cout << visit[end] << "\n";
	cout << st.size() << "\n";
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
}