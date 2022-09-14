#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 25;
const int M = 15;
const int INF = 987654321;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int w, h;

long long ans;

bool chk[M] = {};

char map[N][N] = {};

int visit[N][N] = {};
int min_dist[M][M] = {};

vector < pair < int, int > > v;

queue < pair < int, int > > q;

void f_initialize() {
    ans = INF;
    v.clear();
    v.resize(1);
    fill_n(chk, M, false);
    for(int i = 0; i < N; i++) {
        fill_n(visit[i], N, INF);
    }
    for(int i = 0; i < M; i++) {
        fill_n(min_dist[i], M, INF);
    }
    while(!q.empty()) {
        q.pop();
    }
}

void f_dfs(int idx, int cnt, long long cost) {
    if(cnt == v.size() - 1) {
        ans = min(ans, cost);
        return;
    }
    
    for(int i = 0; i < v.size(); i++) {
        if(!chk[i]) {
            chk[i] = true;
            f_dfs(i, cnt + 1, cost + min_dist[idx][i]);
            chk[i] = false;
        }
    }
}

bool f_check(int y, int x) {
    if(y < 0 || y >= h) return false;
    if(x < 0 || x >= w) return false;
    if(map[y][x] == 'x') return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(true) {
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        f_initialize();
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> map[i][j];
                if(map[i][j] == 'o') v[0] = make_pair(i, j);
                else if(map[i][j] == '*') v.push_back(make_pair(i, j));
            }
        }
        
        for(int i = 0; i < v.size(); i++) {
            for(int k = 0; k < N; k++) {
                fill_n(visit[k], N, INF);
            }
            while(!q.empty()) {
                q.pop();
            }
            int sy = v[i].first;
            int sx = v[i].second;
            q.push(make_pair(sy, sx));
            visit[sy][sx] = 0;
            while(!q.empty()) {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                
                for(int k = 0; k < 4; k++) {
                    int ny = y + dy[k];
                    int nx = x + dx[k];
                    if(f_check(ny, nx)) {
                        if(visit[ny][nx] > visit[y][x] + 1) {
                            visit[ny][nx] = visit[y][x] + 1;
                            q.push(make_pair(ny, nx));
                        }
                    }
                }
            }
            for(int j = i + 1; j < v.size(); j++) {
                min_dist[i][j] = visit[v[j].first][v[j].second];
                min_dist[j][i] = visit[v[j].first][v[j].second];
            }
        }
        chk[0] = true;
        f_dfs(0, 0, 0);
        if(ans >= INF) cout << "-1" << "\n";
        else cout << ans << "\n";
    }
    return 0;
}