#include <string>
#include <vector>

using namespace std;

bool f_check(int y, int x, int n, int m) {
    if(y > n || y < -n) return false;
    if(x > m || x < -m) return false;
    return true;
}

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    int y = 0, x = 0;
    for(int i = 0; i < keyinput.size(); i++) {
        int dy, dx;
        if(keyinput[i] == "up") {
            dx = 0;
            dy = 1;
        }
        else if(keyinput[i] == "down") {
            dx = 0;
            dy = -1;
        }
        else if(keyinput[i] == "left") {
            dx = -1;
            dy = 0;
        }
        else if(keyinput[i] == "right") {
            dx = 1;
            dy = 0;
        }
        if(f_check(y + dy, x + dx, board[1] / 2, board[0]/ 2)) {
            y += dy;
            x += dx;
        }
    }
    answer.push_back(x);
    answer.push_back(y);
    return answer;
}