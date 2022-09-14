#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>

using namespace std;

const int N = 105;
const int Alphabets = 26;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int ans;
int h, w;

char map[N][N] = {};

bool visit[N][N] = {};
bool key[Alphabets] = {};

void f_initialize() {
    ans = 0;
    fill_n(key, Alphabets, false);
    for(int i = 0; i < N; i++) {
        fill_n(visit[i], N, false);
    }
}

bool f_check(int y, int x) {
    if(y < 0 || y >= h) return false;
    if(x < 0 || x >= w) return false;
    if(map[y][x] == '*') return false;
    if(map[y][x] >= 'A' && map[y][x] <= 'Z') return false;
    if(visit[y][x]) return false;
    return true;
}

void f_bfs() {
    queue < pair < int, int > > q;
    q.push(make_pair(0, 0));
    visit[0][0] = true;
    
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if(f_check(ny, nx)) {
                if(map[ny][nx] >= 'a' && map[ny][nx] <= 'z') {
                    char c = map[ny][nx];
                    if(key[c - 'a'] == false) {
                        key[c - 'a'] = true;
                        for(int i = 0; i < h; i++) {
                            for(int j = 0; j < w; j++) {
                                if(map[i][j] == (char)toupper(c)) map[i][j] = '.'; 
                            }
                        }
                        
                        for(int i = 0; i < N; i++) {
                            fill_n(visit[i], N, false);
                        }
                        while(!q.empty()) {
                            q.pop();
                        }
                        q.push(make_pair(ny, nx));
                        visit[ny][nx] = true;
                        break;
                    }
                }
                
                else if(map[ny][nx] == '$') {
                    ans++;
                    map[ny][nx] = '.';
                }
                q.push(make_pair(ny, nx));
                visit[ny][nx] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        f_initialize();
        cin >> h >> w;
        h += 2; w += 2;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(i == 0 || i == h - 1 || j == 0 || j == w - 1) map[i][j] = '.';
                else cin >> map[i][j];
            }
        }
        string st;
        cin >> st;
        if(st != "0") {
            for(int k = 0; k < st.size(); k++) {
                char c = st[k];
                key[c - 'a'] = true;
                for(int i = 0; i < h; i++) {
                    for(int j = 0; j < w; j++) {
                        if(map[i][j] == (char)toupper(c)) map[i][j] = '.';
                    }
                }
            }
        }
        f_bfs();
        cout << ans << "\n";
    }
    return 0;
}