#include <iostream>
#include <algorithm>

using namespace std;

const int N = 25;
const int Alphabets = 26;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int n, m;
int ans = 0;
int cnt = 0;

bool visit[Alphabets] = {};

char board[N][N] = {};

bool f_check(int y, int x) {
    if(y < 0 || y >= n) return false;
    if(x < 0 || x >= m) return false;
    if(visit[board[y][x] - 'A']) return false;
    return true;
}

void f_dfs(int y, int x) {
    cnt++;
    visit[board[y][x] - 'A'] = true;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(f_check(ny, nx)) f_dfs(ny, nx);
    }
    ans = max(ans, cnt);
    cnt--;
    visit[board[y][x] - 'A'] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    
    f_dfs(0, 0);
    cout << ans;
}