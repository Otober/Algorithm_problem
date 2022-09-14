#include <iostream>
#define N 100005
#define devive 1000000009

using namespace std;

long long dp[N][4] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
        for(int i = 4; i <= n; i++) {
            for(int j = 1; j <= 3; j++) {
                if(j == 1) {
                    dp[i][j] = dp[i - 1][2] + dp[i - 1][3];
                }
                else if(j == 2) {
                    dp[i][j] = dp[i - 2][1] + dp[i - 2][3];
                }
                else {
                    dp[i][j] = dp[i - 3][1] + dp[i - 3][2];
                }
                dp[i][j] %= devive;
            }
        }
        cout << (dp[n][1] + dp[n][2] + dp[n][3]) % devive << "\n";
    }
    return 0;
}