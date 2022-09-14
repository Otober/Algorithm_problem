#include <iostream>
#include <algorithm>

using namespace std;

const int N = 105;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int n, cnt;
int ans = 0;

bool visit[N][N] = {};

int arr[N][N] = {};

void f_initialize() {
    cnt = 0;
    for(int i = 0; i < N; i++) {
        fill_n(visit[i], N, false);
    }
}

bool f_check(int y, int x, int high) {
    if(y < 0 || y >= n) return false;
    if(x < 0 || x >= n) return false;
    if(visit[y][x]) return false;
    if(arr[y][x] <= high) return false;
    return true;
}

void f_dfs(int y, int x, int high) {
    visit[y][x] = true;
    
    for(int k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if(f_check(ny, nx, high)) f_dfs(ny, nx, high);
    }
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
    
    for(int k = 0; k < N; k++) {
        f_initialize();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!visit[i][j] && arr[i][j] > k) {
                    cnt++;
                    f_dfs(i, j, k);
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}