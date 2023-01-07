#include <string>
#include <vector>
#include <queue>

using namespace std;

const int N = 35;

queue < pair < int, int > > q;

bool check(vector < string > &board, int i, int j) {
    if(board[i][j] == '0') return false;
    if(board[i][j] != board[i + 1][j]) return false;
    if(board[i][j] != board[i][j + 1]) return false;
    if(board[i][j] != board[i + 1][j + 1]) return false;
    return true;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool flag = true;
    while(flag) {
        flag = false;
        for(int i = 0; i < m - 1; i++) {
            for(int j = 0; j < n - 1; j++) {
                if(check(board, i, j)) {
                    q.push(make_pair(i, j));
                    q.push(make_pair(i + 1, j));
                    q.push(make_pair(i, j + 1));
                    q.push(make_pair(i + 1, j + 1));
                }
            }
        }
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(board[i][j] != '0' && board[i][j] != '1') {
                answer++;
                board[i][j] = '1';
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = m - 1; j >= 0; j--) {
                if(board[j][i] == '1') {
                    for(int k = j; k > 0; k--) {
                        board[k][i] = board[k - 1][i];
                    }
                    board[0][i] = '0';
                    j++;
                    flag = true;
                }
            }
        }
    }
    return answer;
}