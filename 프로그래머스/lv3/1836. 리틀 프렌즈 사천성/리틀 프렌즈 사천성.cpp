#include <string>
#include <vector>

using namespace std;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

struct Pos {
    int x, y;
};

int N, M;
vector < string > Board;
vector < vector < Pos > > alphabets;

bool f_line(char c, Pos from, Pos to) {
    for(int i = 0; i < 4; i++) {
        int ny = from.y + dy[i];
        int nx = from.x + dx[i];
        while(!(ny < 0 || ny >= N) && !(nx < 0 || nx >= M)) {
            if(ny == to.y && nx == to.x) return true;
            if(Board[nx][ny] != '.') break;
            
            for(int j = (i + 1) % 2; j < 4; j += 2) {
                int nny = ny + dy[j];
                int nnx = nx + dx[j];
                while(!(nny < 0 || nny >= N) && !(nnx < 0 || nnx >= M)) {
                    if(nnx == to.x && nny == to.y) return true;
                    if(Board[nnx][nny] != '.') break;
                    nny += dy[j];
                    nnx += dx[j];
                }
            }
            ny += dy[i];
            nx += dx[i];
        }
    }
    return false;
}

bool f_game(string &answer, int cnt) {
    while(true) {
        bool flag = false;
        for(int i = 0; i < 26; i++) {
            if(!alphabets[i].empty()) {
                char c = 'A' + i;
                Pos from = alphabets[i][0];
                Pos to = alphabets[i][1];
                
                if(f_line(c, from, to)) {
                    answer += c;
                    Board[from.x][from.y] = '.';
                    Board[to.x][to.y] = '.';
                    alphabets[i].clear();
                    flag = true;
                    cnt -= 2;
                    break;
                }
            }
        }
        if(!flag) break;
    }
    return (cnt == 0);
}

string solution(int m, int n, vector < string > board) {
    string answer = "";
    M = m;
    N = n;
    Board = board;
    alphabets = vector < vector < Pos > >(26);
    
    int cnt = 0;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j] >= 'A' && board[i][j] <= 'Z') {
                cnt++;
                alphabets[board[i][j] - 'A'].push_back({i, j});
            }
        }
    }
    if(f_game(answer, cnt)) return answer;
    else return "IMPOSSIBLE";
}