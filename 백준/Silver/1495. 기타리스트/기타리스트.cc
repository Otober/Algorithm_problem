#include <iostream>

using namespace std;

const int N = 105;
const int M = 1005;

int n, s, m;

int arr[N] = {};

bool dp[N][M] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> s >> m;
    for(int i = 0; i < N; i++) {
        fill_n(dp[i], M, false);
    }
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dp[0][s] = true;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(dp[i - 1][j] == false) continue;
            if(j + arr[i] <= m) dp[i][j + arr[i]] = true;
            if(j - arr[i] >= 0) dp[i][j - arr[i]] = true;
        }
    }
    int ans = -1;
    for(int i = m; i >= 0; i--) {
        if(dp[n][i]) ans = max(ans, i);
    }
    if(ans == -1) cout << "-1";
    else cout << ans;
    return 0;
}