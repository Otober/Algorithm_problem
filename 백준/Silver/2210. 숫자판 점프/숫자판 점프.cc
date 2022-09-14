#include <iostream>
#include <map>

using namespace std;

const int N = 5;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int arr[N][N] = {};

map < int, bool > mp;

bool f_check(int y, int x) {
    if(y < 0 || y >= N) return false;
    if(x < 0 || x >= N) return false;
    return true;
}

void f_dfs(int y, int x, int sum, int cnt) {
    if(cnt == 6) {
        if(mp.find(sum) == mp.end()) {
            mp.insert(make_pair(sum, true));
        }
        return;
    }
    else {
        for(int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if(f_check(ny, nx)) f_dfs(ny, nx, sum * 10 + arr[ny][nx], cnt + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            f_dfs(i, j, arr[i][j], 1);
        }
    }
    cout << mp.size();
    return 0;
}