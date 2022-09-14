#include <iostream>
#include <queue>

using namespace std;

const int N = 13;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

bool flag = false;

int n, m;
int ans = 0;

bool visit[N][N][N][N] = {};

char board[N][N] = {};

queue < pair < int, int > > redball;
queue < pair < int, int > > blueball;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'R' || board[i][j] == 'B') {
                if(board[i][j] == 'R') redball.push(make_pair(i, j));
                else blueball.push(make_pair(i, j));
                board[i][j] = '.';
            }
        }
    }
    visit[redball.front().first][redball.front().second][blueball.front().first][blueball.front().second] = true;
    
    while(!redball.empty()) {
        int t = redball.size();
        while(t--) {
            int ry = redball.front().first;
            int rx = redball.front().second;
            int by = blueball.front().first;
            int bx = blueball.front().second;
            redball.pop(); blueball.pop();
            
            if(ans > 10) break;
            if(board[ry][rx] == 'O') {
                flag = true;
                break;
            }
            for(int i = 0; i < 4; i++) {
                int nry = ry + dy[i];
                int nrx = rx + dx[i];
                int nby = by + dy[i];
                int nbx = bx + dx[i];
                
                while(true) {
                    if(board[nry][nrx] == '#') {
                        nry -= dy[i];
                        nrx -= dx[i];
                        break;
                    }
                    if(board[nry][nrx] == 'O') break;
                    nry += dy[i];
                    nrx += dx[i];
                }
                while(true) {
                    if(board[nby][nbx] == '#') {
                        nby -= dy[i];
                        nbx -= dx[i];
                        break;
                    }
                    if(board[nby][nbx] == 'O') break;
                    nby += dy[i];
                    nbx += dx[i];
                }
                
                if(board[nby][nbx] == 'O') continue;
                if(nry == nby && nrx == nbx) {
                    switch(i) {
                        case 0 : (rx > bx) ? nbx-- : nrx--; break;
                        case 1 : (ry > by) ? nby-- : nry--; break;
                        case 2 : (rx > bx) ? nrx++ : nbx++; break;
                        case 3 : (ry > by) ? nry++ : nby++; break;
                    }
                }
                if(visit[nry][nrx][nby][nbx]) continue;
                redball.push(make_pair(nry, nrx));
                blueball.push(make_pair(nby, nbx));
                visit[nry][nrx][nby][nbx] = true;
            }
        }
        if(flag) break;
        else ans++;
    }
    if(flag) cout << "1";
    else cout << "0";
    return 0;
}