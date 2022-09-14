#include <iostream>
#include <queue>
#define N 105

using namespace std;

int m, n, h;
int arr[N][N][N] = {};
int dy[6] = {0, 0, 1, 0, 0, -1};
int dx[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {1, 0, 0, -1, 0, 0};

queue < pair < pair < int, int >, int > >q;

bool check(int y, int x, int z) {
    if(y < 0 || y >= n) return false;
    if(x < 0 || x >= m) return false;
    if(z < 0 || z >= h) return false;
    if(arr[y][x][z] == 1) return false;
    if(arr[y][x][z] == -1) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tomato_cnt = 0;
    int last_cnt = 0;
    int space_cnt = 0;
    int day = 0;
    
    cin >> m >> n >> h;
    
    for(int k = 0; k < h; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> arr[i][j][k];
                if(arr[i][j][k] == 1) {
                    tomato_cnt++;
                    q.push(make_pair(make_pair(i, j), k));
                }
                else if(arr[i][j][k] == -1) space_cnt++;
            }
        }
    }
    
    while(true) {
        if(m * n * h - space_cnt == tomato_cnt) {
            cout << day << endl;
            break;
        }
        else if(last_cnt == tomato_cnt) {
            cout << "-1" << endl;
            break;
        }
        int temp = tomato_cnt - last_cnt;
        day++;
        last_cnt = tomato_cnt;
        while(temp--) {
            int y = q.front().first.first;
            int x = q.front().first.second;
            int z = q.front().second;
            q.pop();
            for(int i = 0; i < 6; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                int nz = z + dz[i];
                if(check(ny, nx, nz)) {
                    tomato_cnt++;
                    arr[ny][nx][nz] = 1;
                    q.push(make_pair(make_pair(ny, nx), nz));
                }
            }
        }
    }
    return 0;
}