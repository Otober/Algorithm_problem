#include <iostream>
#define N 1005
#define div_n 10007

using namespace std;

int dp[N][N] = {};

int main() {
    int n,k;
    cin >> n >> k;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            if(i == j || j == 0) dp[i][j] = 1;
            else {
                dp[i][j] = (dp[i- 1][j - 1] + dp[i - 1][j]) % div_n;
            }
        }
    }
    cout << dp[n][k];
    return 0;
}