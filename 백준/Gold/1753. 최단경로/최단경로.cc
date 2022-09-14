#include <iostream>
#include <vector>
#include <queue>
#define N 20005
#define INT_MAX 987654321

using namespace std;

int v, e, st;
int visit[N] = {};
vector < pair < int, int > > adj[N];
priority_queue < pair < int, int > > pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> v >> e;
    cin >> st;
    
    for(int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
    }
    for(int i = 1; i <= v; i++) {
        visit[i] = INT_MAX;
    }
    
    visit[st] = 0;
    pq.push(make_pair(-visit[st], st));
    
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        for(int i = 0; i < adj[now].size(); i++) {
            int next = adj[now][i].first;
            int distance = adj[now][i].second;
            
            if(visit[next] > cost + distance) {
                visit[next] = cost + distance;
                pq.push(make_pair(-visit[next], next));
            }
        }
    }
    for(int i = 1; i <= v; i++) {
        if(visit[i] == INT_MAX) cout << "INF" << "\n";
        else cout << visit[i] << "\n";
    }
    return 0;
}
