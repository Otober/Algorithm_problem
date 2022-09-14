#include <iostream>
#include <vector>
#define N 505
#define INF 987654321

using namespace std;

vector < pair < int, int > > adj[N];
long long visit[N] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    bool cycle = false;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
    }
    
    fill_n(visit + 1, n, INF);
    visit[1] = 0;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 0; k < adj[j].size(); k++) {
                int next = adj[j][k].first;
                int cost = adj[j][k].second;
                if(visit[j] != INF && j != next && visit[next] > visit[j] + cost) {
                    visit[next] = visit[j] + cost;
                    if(i == n) cycle = true;
                }
            }
        }
    }
    
    if(cycle) cout << "-1" << "\n";
    else {
        for(int i = 2; i <= n; i++) {
            if(visit[i] == INF) cout << "-1" << "\n";
            else cout << visit[i] << "\n";
        }
    }
    return 0;
}