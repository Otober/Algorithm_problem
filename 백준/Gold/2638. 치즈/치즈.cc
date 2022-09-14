#include <iostream>

using namespace std;

const int N = 105;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

bool flag;

int n, m;
int ans = 0;

bool visit[N][N] = {};

int arr[N][N] = {};

void f_initialize() {
    flag = true;
    for(int i = 1; i <= n; i++) {
        fill_n(visit[i], m + 1, false);
    }
}

bool f_check(int y, int x) {
    if(y < 1 || y >= n + 1) return false;
    if(x < 1 || x >= m + 1) return false;
    if(arr[y][x] == 1) return false;
    if(visit[y][x]) return false;
    return true;
}

void f_dfs(int y, int x) {
    visit[y][x] = true;
    for(int k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if(f_check(ny, nx)) f_dfs(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    
    while(true) {
        f_initialize();
        f_dfs(1, 1);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(arr[i][j] == 1) {
                    int cnt = 0;
                    for(int k = 0; k < 4; k++) {
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        if(visit[ny][nx]) cnt++;
                    }
                    
                    if(cnt >= 2) {
                        flag = false;
                        arr[i][j] = 0;
                    }
                }
            }
        }
        
        if(flag) {
            cout << ans;
            break;
        }
        else ans++;
    }
    return 0;
}