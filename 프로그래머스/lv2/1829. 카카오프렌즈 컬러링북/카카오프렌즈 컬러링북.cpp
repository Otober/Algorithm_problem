#include <vector>

using namespace std;

const int N = 105;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int tcnt = 0;
int visit[N][N] = {};

bool f_check(int y, int x, int ny, int nx, int m, int n, vector < vector < int > > &picture) {
    if(ny < 0 || ny >= m) return false;
    if(nx < 0 || nx >= n) return false;
    if(visit[ny][nx] != 0) return false;
    if(picture[ny][nx] != picture[y][x]) return false;
    return true;
}

void f_func(int y, int x, int m, int n, vector < vector < int > > &picture, int cnt) {
    visit[y][x] = cnt;
    tcnt++;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(f_check(y, x, ny, nx, m, n, picture)) f_func(ny, nx, m, n, picture, cnt);
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            visit[i][j] = 0;
        }
    }
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(visit[i][j] == 0 && picture[i][j] != 0) {
                f_func(i, j, m, n, picture, ++number_of_area);
                max_size_of_one_area = max(tcnt, max_size_of_one_area);
                tcnt = 0;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}