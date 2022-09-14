#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1005;

const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};

int n, m;
int cnt = 0;
int temp = 0;
int total = 0;
int ripe_fruit = 0;

bool visit[N][N] = {};

int box[N][N] = {};

queue < pair < int, int > > q;

bool f_check(int y, int x) {
    if(y < 0 || y >= m) return false;
    if(x < 0 || x >= n) return false;
    if(visit[y][x] == true) return false;
    if(box[y][x] != 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    total = n * m;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> box[i][j];
            if(box[i][j] == -1) total--;
            if(box[i][j] == 1) {
                ripe_fruit++;
                temp++;
                visit[i][j] = true;
                q.push(make_pair(i ,j));
            }
        }
    }
    
    while(ripe_fruit < total) {
        cnt++;
        int t = temp;
        temp = 0;
        for(int i = 0; i < t; i++) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for(int j = 0; j < 4; j++) {
                int ny = y + dy[j];
                int nx = x + dx[j];
                if(f_check(ny, nx)) {
                    visit[ny][nx] = true;
                    temp++;
                    q.push(make_pair(ny, nx));
                    box[ny][nx] = 1;
                }
            }
        }
        if(temp == 0) break;
        ripe_fruit += temp;
    } 
    if(ripe_fruit == total) cout << cnt;
    else cout << -1;
    return 0;
}