#include <iostream>
#define N 505

using namespace std;

int n, m;
int ans = 0;
int arr[N][N] = {};
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
bool visit[N][N] = {};

int f_max(int &a, int &b) {
    return a > b ? a : b;
}

bool f_check(int y, int x) {
    if(y < 0 || y >= n) return false;
    if(x < 0 || x >= m) return false;
    if(visit[y][x] == true) return false;
    return true;
}

void f_bfs(int y, int x, int cnt, int sum) {
    if(cnt == 3) {
        ans = f_max(ans, sum);
        return;
    }
    visit[y][x] = true;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(f_check(ny, nx)) {
            f_bfs(ny, nx, cnt + 1, sum + arr[ny][nx]);
        }
    }
    visit[y][x] = false;
}

//ㅏ
void f_shape1(int y, int x) {
    int temp;
    temp = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 1][x + 1];
    ans = f_max(ans, temp);
}

//ㅓ
void f_shape2(int y, int x) {
    int temp;
    temp = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 1][x - 1];
    ans = f_max(ans, temp);
}

//ㅗ
void f_shape3(int y, int x) {
    int temp;
    temp = arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y - 1][x + 1];
    ans = f_max(ans, temp);
}


//ㅜ
void f_shape4(int y, int x) {
    int temp;
    temp = arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y + 1][x + 1];
    ans = f_max(ans, temp);
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
            f_bfs(i, j, 0, arr[i][j]);
            if(i < n - 2 && j < m - 1) f_shape1(i, j);
            if(i < n - 2 && j > 0) f_shape2(i, j);
            if(i > 0 && j < m - 2) f_shape3(i, j);
            if(i < n - 1 && j < m - 2) f_shape4(i, j);
        }
    }
    cout << ans;
    return 0;
}