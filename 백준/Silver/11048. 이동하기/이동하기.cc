#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1005;

int n, m;
int dp[N][N] = {};
int miro[N][N] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> miro[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + miro[i][j];
        }
    }
    cout << dp[n][m];
    return 0;
}