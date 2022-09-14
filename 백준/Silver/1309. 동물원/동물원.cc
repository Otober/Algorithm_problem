#include <iostream>

using namespace std;

const int N = 100005;
const int devive = 9901;

int dp[N][3] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    dp[1][0] = 1; dp[1][1] = 1; dp[1][2] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % devive;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % devive;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % devive;
    }
    cout << (dp[n][0] + dp[n][1] + dp[n][2]) % devive;
    return 0;
}