#include <iostream>
#include <queue>
#include <vector>
#define N 2505
#define INF 987654321

using namespace std;

int n, m;
int ans = INF;
int gas[N] = {};
int dp[N][N] = {};
vector < pair < int, int > > v[N];
priority_queue < pair < int , pair < int, int > > > pq;

int f_min(int &a, int &b) {
    return a < b ? a : b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> gas[i];
        fill_n(dp[i], N, INF);
    }
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    
    pq.push(make_pair(-0, make_pair(1, gas[1])));
    dp[1][gas[1]] = 0;
    
    while(!pq.empty()) {
        int now = pq.top().second.first;
        int cost = pq.top().second.second;
        pq.pop();
        
        if(now == n) {
            ans = f_min(ans, dp[now][cost]);
            continue;
        }
        
        for(int i = 0; i < v[now].size(); i++) {
            int next = v[now][i].first;
            int dist = v[now][i].second;
            
            if(dp[next][cost] > dp[now][cost] + (dist * cost)) {
                dp[next][cost] = dp[now][cost] + (dist * cost);
                pq.push(make_pair(-dp[next][cost], make_pair(next, cost)));
            }
            if(cost > gas[next]) {
                if(dp[next][gas[next]] > dp[now][cost] + (dist * cost)) {
                    dp[next][gas[next]] = dp[now][cost] + (dist * cost);
                    pq.push(make_pair(-dp[next][gas[next]], make_pair(next, gas[next])));
                }
            }
        }
    }
    cout << ans;
    return 0;
}