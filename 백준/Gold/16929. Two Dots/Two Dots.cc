#include <iostream>

using namespace std;

const int N = 55;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

bool flag = false;

int n, m;

bool visit[N][N] = {};

char arr[N][N] = {};

int dist[N][N] = {};

bool f_check(int y, int x) {
    if(y < 0 || y >= n) return false;
    if(x < 0 || x >= m) return false;
    return true;
}

bool f_dfs(int y, int x, int cnt) {
    if(visit[y][x]) {
        if(cnt - dist[y][x] >= 4) return true;
        else return false;
    }
    
    visit[y][x] = true;
    dist[y][x] = cnt;
    
    for(int k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if(f_check(ny, nx)) {
            if(arr[y][x] == arr[ny][nx]) {
                if(f_dfs(ny, nx, cnt + 1)) return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visit[i][j]) {
                if(f_dfs(i, j, 0)) flag = true;
            }
        }
    }
    if(flag) cout << "Yes";
    else cout << "No";
    return 0;
}