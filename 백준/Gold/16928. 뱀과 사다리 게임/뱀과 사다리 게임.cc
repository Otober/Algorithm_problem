#include <iostream>
#include <queue>

using namespace std;

const int N = 105;
const int INF = 987654321;

const int d[6] = { 1, 2, 3, 4, 5, 6 };

int arr[N] = {};
int visit[N] = {};

priority_queue < pair < int, int > > pq;

bool f_check(int node) {
	if (node > 100) return false;
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < N; i++) {
		arr[i] = i;
		visit[i] = INF;
	}
	for (int i = 0; i < n + m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a] = b;
	}

	visit[1] = 0;
	pq.push(make_pair(-visit[1], 1));
	while (!pq.empty()) {
		int now = pq.top().second;
		if (now == 100) {
			cout << -pq.top().first;
			break;
		}
		pq.pop();

		for (int k = 0; k < 6; k++) {
			int next = now + d[k];
			if (f_check(next)) {
				next = arr[next];
				if (visit[next] > visit[now] + 1) {
					visit[next] = visit[now] + 1;
					pq.push(make_pair(-visit[next], next));
				}
			}
		}
	}
	return 0;
}