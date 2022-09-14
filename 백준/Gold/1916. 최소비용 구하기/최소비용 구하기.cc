#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1005;
const int INF = 987654321;

int visit[N] = {};

vector < pair < int, int > > v[N];

priority_queue < pair < int, int > >pq;

void f_initialize() {
	fill_n(visit, N, INF);
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
		v[a].push_back(make_pair(b, c));
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
				pq.push(make_pair(-visit[next], next));
			}
		}
	}
	cout << visit[end];
}