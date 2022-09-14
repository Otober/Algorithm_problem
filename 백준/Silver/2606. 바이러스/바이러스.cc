#include <iostream>
#include <queue>
#include <vector>
#define N 105

using namespace std;

vector<int> adj[N];
queue<int> pq;
bool visit[N];

int main()
{
	int n,t;
	int cnt = 0;
	cin >> n >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	pq.push(1);
	
	while (!pq.empty()) {
		int s = pq.front();
		visit[s] = true;
		pq.pop();
		for (int i = 0; i < adj[s].size(); i++) {
			int e = adj[s][i];
			if (visit[e] == false) {
				pq.push(e);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (visit[i] == 1) cnt++;
	}
	cout << cnt - 1 << endl;
	return 0;
}