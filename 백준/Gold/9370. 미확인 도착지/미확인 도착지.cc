#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INT_MAX 2100000000
#define N 2005
#define endl "\n"

using namespace std;

int n, m, t, s, g, h;
int visit_s[N] = {};
int visit_g[N] = {};
int visit_h[N] = {};
vector < pair <int, int > > adj[N];
vector < int > candidate;

void Dijkstra(int st, int visit[]) {
    priority_queue < pair <int, int > > pq;
    visit[st] = 0;
    pq.push(make_pair(-visit[st], st));
    
    while(!pq.empty()) {
        int now = pq.top().second;
        pq.pop();
        for(int i = 0; i < adj[now].size(); i++) {
            int next = adj[now][i].first;
            int cost = adj[now][i].second;
            if(visit[next] > visit[now] + cost) {
                visit[next] = visit[now] + cost;
                pq.push(make_pair(-visit[next], next));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;
    while(tc--) {
        for(int i = 0; i < N; i++) {
            adj[i].clear();
            visit_s[i] = INT_MAX;
            visit_g[i] = INT_MAX;
            visit_h[i] = INT_MAX;
        }
        candidate.clear();
        
        cin >> n >> m >> t >> s >> g >> h;
        for(int i = 0; i < m; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            adj[a].push_back(make_pair(b, d));
            adj[b].push_back(make_pair(a, d));
        }
        for(int i = 0; i < t; i++) {
            int temp;
            cin >> temp;
            candidate.push_back(temp);
        }
        
        Dijkstra(s, visit_s);
        Dijkstra(g, visit_g);
        int dist_gh = visit_g[h];
        Dijkstra(h, visit_h);
        
        sort(candidate.begin(), candidate.end());
        for(int i = 0; i < candidate.size(); i++) {
            int temp = candidate[i];
            if(visit_s[temp] == visit_s[g] + dist_gh + visit_h[temp]) cout << temp << " ";
            else if(visit_s[temp] == visit_s[h] + dist_gh + visit_g[temp]) cout << temp << " ";
        }
        cout << endl;
    }
    return 0;
}