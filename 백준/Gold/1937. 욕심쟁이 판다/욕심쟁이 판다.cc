#include <iostream>
#include <algorithm>
#define N 505

using namespace std;

int n;
int ans = 0;

int arr[N][N] = {};
int visit[N][N] = {};
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool f_check(int y, int x, int ny, int nx) {
    if(ny < 0 || ny >= n) return false;
    if(nx < 0 || nx >= n) return false;
    if(arr[y][x] >= arr[ny][nx]) return false;
    return true;
}

int f_dfs(int y, int x) {
    if(visit[y][x]) return visit[y][x];
    
    visit[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(f_check(y, x, ny, nx)) visit[y][x] = max(visit[y][x], f_dfs(ny, nx) + 1);
    }
    return visit[y][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans = max(ans, f_dfs(i, j));
        }
    }
    cout << ans;
    return 0;
}