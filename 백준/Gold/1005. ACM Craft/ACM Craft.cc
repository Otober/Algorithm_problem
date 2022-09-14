#include <iostream>
#include <vector>
#include <queue>
#define N 1005

using namespace std;

int ans;
int n, k, w;
int dp[N] = {};
int arr[N] = {};
int inDegree[N] = {};

vector < int > v[N];
queue < int > q;

void f_initialize(int n) {
    fill_n(dp, n + 1, 0);
    fill_n(arr, n + 1, 0);
    fill_n(inDegree, n + 1, 0);
    for(int i = 0; i <= n; i++) v[i].clear();
    while(!q.empty()) q.pop();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        f_initialize(n);
        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        for(int i = 1; i <= k; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            inDegree[b]++;
        }
        cin >> w;
        for(int i = 1; i <= n; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
                dp[i] += arr[i];
            }
        }
        
        while(!q.empty()) {
            int here = q.front();
            q.pop();
            
            for(int next : v[here]) {
                inDegree[next]--;
                if(inDegree[next] == 0) q.push(next);
                if(dp[next] < dp[here] + arr[next]) dp[next] = dp[here] + arr[next];
            }
        }
        cout << dp[w] << "\n";
    }
    return 0;
}