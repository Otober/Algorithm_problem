#include <iostream>

using namespace std;

const int N = 205;
const int devive = 1000000000;

int dp[N][N] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    for(int i = 1; i <= k; i++) {
        dp[i][0] = 1;
    }
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % devive;
        }
    }
    cout << dp[k][n];
    return 0;
}