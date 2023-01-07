#include<vector>

using namespace std;

const int N = 1005;

int dp[N][N] = {};

int solution(vector<vector<int>> board) {
    int answer = 0;
    int row = board.size();
    int colum = board[0].size();
    for(int i = 0; i <= row; i++) {
        for(int j = 0; j <= colum; j++) {
            dp[i][j] = 0;
        }
    }
    
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= colum; j++) {
            if(board[i - 1][j - 1] == 1) {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                answer = max(dp[i][j], answer);
            }
        }
    }
    return answer * answer;
}