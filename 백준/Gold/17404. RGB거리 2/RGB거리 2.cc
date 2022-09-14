#include <iostream>
#define N 1005
#define INF 987654321

using namespace std;

int f_min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, ans = INF;
    int arr[N][4] = {};
    int dp[N][4] = {};
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 3; j++) {
            cin >> arr[i][j];
        }
    }
    
    for(int k = 1; k <= 3; k++) {
        for(int i = 0; i <= 3; i++) {
            if(i == k) dp[1][i] = arr[1][i];
            else dp[1][i] = INF;
        }
        for(int i = 2; i <= n; i++) {
            dp[i][1] = f_min(dp[i - 1][2], dp[i - 1][3]) + arr[i][1];
            dp[i][2] = f_min(dp[i - 1][3], dp[i - 1][1]) + arr[i][2];
            dp[i][3] = f_min(dp[i - 1][1], dp[i - 1][2]) + arr[i][3];
        }
        for(int i = 1; i <= 3; i++) {
            if(i == k) continue;
            else ans = f_min(ans, dp[n][i]);
        }
    } 
    cout << ans << endl;
    return 0;
}