#include <vector>
#include <queue>

using namespace std;

const int N = 105;
const int INT_MAX = 987654321;

const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

int n, m;

int visit[N][N] = {};
int map[N][N] = {};

queue < pair < int, int > > q;

bool f_check(int y, int x, int ny, int nx) {
    if (ny < 0 || ny >= n) return false;
    if (nx < 0 || nx >= m) return false;
    if (map[ny][nx] == 0) return false;
    if (visit[y][x] + 1 >= visit[ny][nx]) return false;
    return true;
}

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    n = maps.size();
    m = maps[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visit[i][j] = INT_MAX;
            map[i][j] = maps[i][j];
        }
    }

    visit[0][0] = 1;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if (f_check(y, x, ny, nx)) {
                visit[ny][nx] = visit[y][x] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }
    if (visit[n - 1][m - 1] != INT_MAX) answer = visit[n - 1][m - 1];
    return answer;
}