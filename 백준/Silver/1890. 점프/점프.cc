#include <iostream>

using namespace std;

const int N = 105;

const int dy[2] = {1, 0};
const int dx[2] = {0, 1};

int n;

int board[N][N] = {};

long long dp[N][N] = {};

bool f_check(int y, int x) {
    if(y >= n) return false;
    if(x >= n) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == n - 1 && j == n - 1) continue;
            for(int k = 0; k < 2; k++) {
                int ny = i + dy[k] * board[i][j];
                int nx = j + dx[k] * board[i][j];
                if(f_check(ny, nx)) dp[ny][nx] += dp[i][j];
            }
        }
    }
    cout << dp[n - 1][n - 1];
    return 0;
}