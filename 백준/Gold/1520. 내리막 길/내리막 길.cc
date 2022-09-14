#include <iostream>
#define N 505

using namespace std;

int m, n;
int map[N][N] = {};
int dp[N][N] = {};
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

bool check(int y, int x, int ny, int nx) {
    if(y < 0 || y >= m) return false;
    if(x < 0 || x >= n) return false;
    if(map[y][x] >= map[ny][nx]) return false;
    return true;
}

int dfs(int y, int x) {
    if(y == 0 && x == 0) return 1;
    if(dp[y][x] == -1) {
        dp[y][x] = 0;
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(check(y, x, ny, nx)) {
                dp[y][x] += dfs(ny, nx);
            }
        }
    }
    return dp[y][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> m >> n;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
    
    cout << dfs(m - 1, n - 1);
    return 0;
}