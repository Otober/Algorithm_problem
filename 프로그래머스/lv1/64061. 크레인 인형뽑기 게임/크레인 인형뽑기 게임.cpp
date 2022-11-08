#include <string>
#include <vector>
#include <stack>

using namespace std;

const int N = 35;

stack < int > st[N];
stack < int > result;
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    for(int i = board.size() - 1; i >= 0; i--) {
        for(int j = 0; j < board[i].size(); j++) {
            if(board[i][j] != 0) st[j + 1].push(board[i][j]);
        }
    }
    
    for(int i = 0; i < moves.size(); i++) {
        if(st[moves[i]].empty()) continue;
        int temp = st[moves[i]].top();
        st[moves[i]].pop();
        if(result.empty()) result.push(temp);
        else {
            if(result.top() == temp) {
                answer += 2;
                result.pop();
            }
            else result.push(temp);
        }
    }
    return answer;
}