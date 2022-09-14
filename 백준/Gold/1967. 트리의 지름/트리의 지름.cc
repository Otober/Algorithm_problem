#include <iostream>
#include <vector>
#include <queue>
#define N 10005
#define INF 987654321

using namespace std;

vector < pair < int, int > > adj[N];
priority_queue < pair < int, int > > pq;
int visit[N] = {};
int n;

int f_bfs(int root) {
    fill_n(visit + 1, n, INF);
    visit[root] = 0;
    pq.push(make_pair(-visit[root], root));
    
    while(!pq.empty()) {
        int here = pq.top().second;
        pq.pop();
        for(int i = 0; i < adj[here].size(); i++) {
            int next = adj[here][i].first;
            int cost = adj[here][i].second;
            if(visit[next] > visit[here] + cost) {
                visit[next] = visit[here] + cost;
                pq.push(make_pair(-visit[next], next));
            }
        }
    }
    int temp = 1;
    for(int i = 1; i <= n; i++) {
        if(visit[temp] < visit[i]) temp = i;
    }
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }
    
    cout << visit[f_bfs(f_bfs(1))] << endl;
    return 0;
}