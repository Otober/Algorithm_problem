#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

bool visit[505][505][4] = {};

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

vector<string> map;

int f_dfs(int y, int x, int k, int cnt) {
    if(visit[y][x][k]) return cnt;
    visit[y][x][k] = true;
    
    if(map[y][x] == 'R') {
        k++;
        if(k >= 4) k = 0;
    }
    else if(map[y][x] == 'L') {
        k--;
        if(k < 0) k = 3;
    }
    
    int ny = y + dy[k];
    int nx = x + dx[k];
    if(ny >= N) ny = 0;
    if(ny < 0) ny = N - 1;
    if(nx >= M) nx = 0;
    if(nx < 0) nx = M - 1;
    
    return f_dfs(ny, nx, k, cnt + 1);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    N = grid.size();
    M = grid[0].size();
    map = grid;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            for(int k = 0; k < 4; k++) {
                int temp = f_dfs(i, j, k, 0);
                if(temp != 0) answer.push_back(temp);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}