#include <iostream>
#define N 55

using namespace std;

int w, h;
int cnt = 0;
int arr[N][N] = {};
int visit[N][N] = {};
const int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void f_initialize(int w, int h) {
    cnt = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            visit[i][j] = 0;
        }
    }
}

bool f_check(int y, int x) {
    if(y < 0 || y >= h) return false;
    if(x < 0 || x >= w) return false;
    if(arr[y][x] == 0) return false;
    if(visit[y][x] != 0) return false;
    return true;
}

void f_dfs(int y, int x) {
    visit[y][x] = cnt;
    for(int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(f_check(ny, nx)) {
            f_dfs(ny, nx);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(true) {
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        
        f_initialize(w, h);
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> arr[i][j];
            }
        }
        
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(arr[i][j] == 1 && visit[i][j] == 0) {
                    cnt++;
                    f_dfs(i, j);
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0; 
}