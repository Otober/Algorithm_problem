#include <iostream>

using namespace std;

const int N = 10005;

int dp[N][4] = {};

void f_initialize() {
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            dp[i][j] = 1;
            if(i < j) dp[i][j] = 0;
        }
    }
    for(int i = 4; i < N; i++) {
        dp[i][1] = dp[i - 1][1];
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
        dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    f_initialize();
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
    }
    return 0;
}