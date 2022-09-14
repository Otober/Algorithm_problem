#include <iostream>
#define N 1000005
#define INF 987654321
using namespace std;

int dp[N][2] = {};

void f_print(int n) {
    if(n == 0) return;
    f_print(dp[n][1]);
    cout << n << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++) dp[i][0] = INF;
    dp[n][0] = 0;
    for(int i = n; i >= 1; i--) {
        if(dp[i][0] == INF) continue;
        if(i % 3 == 0) {
            if(dp[i / 3][0] > dp[i][0] + 1) {
                dp[i / 3][0] = dp[i][0] + 1;
                dp[i / 3][1] = i;
            }
        }
        if(i % 2 == 0) {
            if(dp[i / 2][0] > dp[i][0] + 1) {
                dp[i / 2][0] = dp[i][0] + 1;
                dp[i / 2][1] = i;
            }
        }
        if(i > 1) {
            if(dp[i - 1][0] > dp[i][0] + 1) {
                dp[i - 1][0] = dp[i][0] + 1;
                dp[i - 1][1] = i;
            }
        }
    }
    
    cout << dp[1][0] << endl;
    f_print(1);
    return 0;
}