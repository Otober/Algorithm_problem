#include <iostream>

using namespace std;

const int N = 305;

const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};

int n, m;
int iceberg = 1;
int ans = 0;

bool visit[N][N] = {};

int arctic[N][N] = {};
int molten[N][N] = {};

bool f_check(int y, int x, int (*arr)[N], bool flag) {
    if(y < 0 || y >= n) return false;
    if(x < 0 || x >= m) return false;
    if(flag) {
        if(arr[y][x] != 0) return false;
    }
    else if(arr[y][x] == 0) return false;
    if(visit[y][x]) return false;
    return true;
}

void f_melting(int y, int x) {
    int cnt = 0;
    for(int k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if(f_check(ny, nx, arctic, true)) cnt++;
    }
    molten[y][x] = ((arctic[y][x] - cnt) >= 0) ? arctic[y][x] - cnt : 0;
}

void f_initialize() {
    iceberg = 0;
    for(int i = 0; i < N; i++) {
        fill_n(visit[i], N, false);
    }
}

void f_dfs(int y, int x) {
    visit[y][x] = true;
    
    for(int k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if(f_check(ny, nx, molten, false)) f_dfs(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arctic[i][j];
        }
    }
    
    while(iceberg == 1) {
        ans++;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(arctic[i][j] != 0) {
                    f_melting(i, j);
                }
            }
        }
        
        f_initialize();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visit[i][j] && molten[i][j] != 0) {
                    iceberg++;
                    f_dfs(i, j);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                arctic[i][j] = molten[i][j];
            }
        }
        if(iceberg >= 2) cout << ans;
        if(iceberg == 0) cout << "0";
    }
    return 0;
}