#include <iostream>
#define N 100005

using namespace std;

int dp[2][N] = {};

int f_max(int &a, int &b) {
    return a > b ? a : b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < 2; i++) {
            for(int j = 2; j < n + 2; j++) {
                cin >> dp[i][j];
            }
        }
        for(int j = 2; j < n + 2; j++) {
            for(int i = 0; i < 2; i++) {
                if(i == 1) dp[i][j] += f_max(dp[i - 1][j - 1], dp[i - 1][j - 2]);
                else dp[i][j] += f_max(dp[i + 1][j - 1], dp[i + 1][j - 2]);
            } 
        }
        cout << f_max(dp[0][n + 1], dp[1][n + 1]) << "\n";
    }
    return 0;
}