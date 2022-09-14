#include <iostream>
#include <vector>
#include <queue>
#define N 101
#define INF 987654321

using namespace std;

int f_min(int a, int b) {
    return a < b ? a : b;
}

struct node {
    int pos, cost, time;
    bool operator < (const node &p) const {
        if(this -> time == p.time) return this -> cost > p.cost;
        else this -> time > p.time;
    }
};

int dp[N][N * N] = {};
vector < node > adj[N];
priority_queue < node > pq;

int dijkstar(int n, int m) {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) dp[i][j] = INF;
    }
    
    pq.push({1, 0, 0});
    dp[1][0] = 0;
    while(!pq.empty()) {
        node top = pq.top();
        pq.pop();
        
        int now_pos = top.pos;
        int now_cost = top.cost;
        int now_time = top.time;
        
        if(dp[now_pos][now_cost] < now_time) continue;
        dp[now_pos][now_cost] = now_time;
        
        for(int i = 0; i < adj[now_pos].size(); i++) {
            node next = adj[now_pos][i];
            
            if(m < now_cost + next.cost) continue;
            if(dp[next.pos][now_cost + next.cost] <= now_time + next.time) continue;
            
            pq.push(node{next.pos, now_cost + next.cost, now_time + next.time});
            dp[next.pos][now_cost + next.cost] = now_time + next.time;
        }
    }
    
    int ans = INF;
    for(int i = 0; i <= m; i++) {
        ans = f_min(ans, dp[n][i]);
    }
    return ans;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        for(int i = 0; i <= n; i++) adj[i].clear();
        for(int i = 0; i < k; i++) {
            int u, v, c, d;
            cin >> u >> v >> c >> d;
            adj[u].push_back({v, c, d});
        }
        int ans = dijkstar(n, m);
        if(ans == INF) cout << "Poor KCM\n";
        else cout << ans << "\n";
    }
    return 0;
}