#include <string>
#include <vector>

using namespace std;

const int dy[9] = {1, 1, 0, -1, -1, -1, 0, 1, 0};
const int dx[9] = {0, 1, 1, 1, 0, -1, -1, -1, 0};

int N, M;

bool visit[105][105] = {};

bool f_check(int y, int x) {
    if(y < 0 || y >= N) return false;
    if(x < 0 || x >= M) return false;
    if(visit[y][x]) return false;
    return true;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    N = board.size();
    M = board[0].size();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] == 1) {
                for(int k = 0; k < 9; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if(f_check(ny, nx)) {
                        answer++;
                        visit[ny][nx] = true;
                    }
                }
            }
        }
    }
    return (N * M ) - answer;
}