#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const int N = 105;
const int INT_MAX = 987654321;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int cnt = 0;

int lim_N, lim_M;

char map[N][N] = {};

int visit[N][N] = {};

pair < int, int > s, l, e;

queue < pair < int, int > > q;

bool f_check(int y, int x, int n_y, int n_x) {
    if(n_y < 0 || n_y >= lim_N) return false;
    if(n_x < 0 || n_x >= lim_M) return false;
    if(map[n_y][n_x] == 'X') return false;
    if(visit[y][x] + 1 >= visit[n_y][n_x]) return false;
    return true;
    
}

void f_bfs(pair < int, int > st, pair < int, int > end) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            visit[i][j] = INT_MAX;
        }
    }
    cnt = 0;
    while(!q.empty()) {
        q.pop();
    }
    
    q.push(make_pair(st.first, st.second));
    visit[st.first][st.second] = 0;
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        if(y == end.first && x == end.second) {
            cnt = visit[y][x];
            break;
        }
        
        for(int k = 0; k < 4; k++) {
            int n_y = y + dy[k];
            int n_x = x + dx[k];
            if(f_check(y, x, n_y, n_x)) {
                visit[n_y][n_x] = visit[y][x] + 1;
                q.push(make_pair(n_y, n_x));
            }
        }
    }
}

int solution(vector<string> maps) {
    int answer = -1;
    lim_N = maps.size();
    lim_M = maps[0].size();
    for(int i = 0; i < maps.size(); i++) {
        for(int j = 0; j < maps[i].size(); j++) {
            map[i][j] = maps[i][j];
            if(map[i][j] != 'X') {
                if(map[i][j] == 'S') s = make_pair(i, j);
                else if(map[i][j] == 'L') l = make_pair(i, j);
                else if(map[i][j] == 'E') e = make_pair(i, j);
                map[i][j] = 'O';
            }
        }
    }
    
    f_bfs(s, l);
    if(cnt == 0) answer = -1;
    else {
        answer = cnt;
        f_bfs(l, e);
        if(cnt == 0) answer = -1;
        else answer += cnt;
    }
    cout << cnt << "\n";
    return answer;
}