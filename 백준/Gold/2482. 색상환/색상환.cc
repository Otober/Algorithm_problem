#include <iostream>
#define N 1005
#define mod 1000000003

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    int dp[N][N] = {};
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++) dp[i][1] = i;
    
    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= i / 2; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % mod;
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}