#include <iostream>
#define N 505
#define INT_MAX 2100000000

using namespace std;

int f_min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        int arr[N] = {};
        int dp[N][N] = {};
        int sum[N] = {};
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
            sum[i] = sum[i - 1] + arr[i];
        }
        
        for(int i = 2; i <= n; i++) {
            int dx = i;
            int dy = 1;
            while(dx <= n) {
                dp[dy][dx] = INT_MAX;
                for(int k = dy; k < dx; k++) {
                    dp[dy][dx] = f_min(dp[dy][dx], dp[dy][k] + dp[k + 1][dx] + sum[dx] - sum[dy - 1]);
                }
                dx++;
                dy++;
            }
        }
        cout << dp[1][n] << "\n";
    }
    return 0;
}