#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5;
const int dy[2] = {0, 1};
const int dx[2] = {1, 0};

int n, m;
int ans = 0;

bool visit[N][N] = {};
bool condition[N][N] = {};

int paper[N][N] = {};

int f_dfs(int y, int x) {
    int flag = (condition[y][x]) ? 1 : 0;
    int temp = paper[y][x];
    int ny = y + dy[flag];
    int nx = x + dx[flag];
    visit[y][x] = true;
    while(ny < n && nx < m && condition[ny][nx] == condition[y][x]) {
        visit[ny][nx] = true;
        temp *= 10;
        temp += paper[ny][nx];
        ny += dy[flag];
        nx += dx[flag];
    }
    return temp;
}

int f_sum() {
    int sum = 0;
    for(int i = 0; i < N; i++) {
        fill_n(visit[i], N, false);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visit[i][j]) sum += f_dfs(i, j);
        }
    }
    return sum;
}

void f_solve(int cnt) {
    if(cnt == n * m) {
        ans = max(ans, f_sum());
        return;
    }
    condition[cnt / m][cnt % m] = true;
    f_solve(cnt + 1);
    condition[cnt / m][cnt % m] = false;
    f_solve(cnt + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;
            paper[i][j] = c - '0';
        }
    }
    f_solve(0);
    cout << ans;
    return 0;
}