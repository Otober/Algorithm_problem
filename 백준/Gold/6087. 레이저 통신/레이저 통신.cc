#include <iostream>
#include <queue>

using namespace std;

const int N = 105;
const int INF = 987654321;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int w, h;

char map[N][N] = {};

int visit[N][N] = {};

pair < int, int > s, e;

queue < pair < pair < int, int >, pair < int, int > > > q;

bool f_check(int y, int x) {
    if(y < 0 || y >= h) return false;
    if(x < 0 || x >= w) return false;
    if(map[y][x] == '*') return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    bool flag = true;
    cin >> w >> h;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> map[i][j];
            if(map[i][j] == 'C') {
                if(flag) {
                    s = make_pair(i, j);
                    flag = false;
                }
                else e = make_pair(i, j);
            }
            visit[i][j] = INF;
        }
    }
    
    for(int k = 0; k < 4; k++) {
        q.push(make_pair(make_pair(s.first, s.second), make_pair(k, 0)));
    }
    visit[s.first][s.second] = 0;
    while(!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int dir = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();
        
        for(int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            int ncost = cost;
            
            if(k != dir) ncost++;
            if(f_check(ny, nx)) {
                if(visit[ny][nx] >= ncost) {
                    visit[ny][nx] = ncost;
                    q.push(make_pair(make_pair(ny, nx), make_pair(k, ncost)));
                }
            }
        }
    }
    cout << visit[e.first][e.second];
    return 0;
}