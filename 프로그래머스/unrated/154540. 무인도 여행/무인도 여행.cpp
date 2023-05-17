#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int t_max = 105;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int N, M;

int cnt = 0;

int map[t_max][t_max] = {};
int visit[t_max][t_max] = {};

bool f_check(int ny, int nx) {
    if(ny < 0 || ny >= N) return false;
    if(nx < 0 || nx >= M) return false;
    if(map[ny][nx] == -1) return false;
    if(visit[ny][nx] == true) return false;
    return true;
}

void f_dfs(int y, int x) {
    visit[y][x] = true;
    cnt += map[y][x];
    for(int k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if(f_check(ny, nx)) f_dfs(ny, nx);
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    N = maps.size();
    M = maps[0].size();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(maps[i][j] == 'X') map[i][j] = -1;
            else map[i][j] = maps[i][j] - '0';
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(map[i][j] > 0 && visit[i][j] == false) {
                cnt = 0;
                f_dfs(i, j);
                answer.push_back(cnt);
            }
        }
    }
    if(answer.size() == 0) answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}