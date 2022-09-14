#include <iostream>
#include <algorithm>

using namespace std;

const int N = 105;
const int M = 100005;
const int INF = 987654321;

int n, k;

int dp[M] = {};
int arr[N] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    fill_n(dp, N * N, INF);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[arr[i]] = 1;
    }
    
    for(int i = 1; i <= k; i++) {
        for(int j = 0; j < n; j++) {
            if(i - arr[j] < 0 || dp[i - arr[j]] == INF) continue;
            dp[i] = min(dp[i], 1 + dp[i - arr[j]]);
        }
    }
    
    if(dp[k] == INF) cout << "-1";
    else cout << dp[k];
    return 0;
}