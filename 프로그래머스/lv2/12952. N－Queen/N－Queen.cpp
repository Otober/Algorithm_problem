#include <string>
#include <vector>

using namespace std;

const int N = 15;

bool chess[N][N] = {};
int answer = 0;

bool f_check(int y, int x, int n) {
    for(int i = 0; i < y; i++) {
        if(chess[i][x]) return false;
    }
    int ny = y - 1;
    int nx = x - 1;
    while(ny >= 0 && nx >= 0) {
        if(chess[ny][nx]) return false;
        ny--; nx--;
    }
    ny = y - 1;
    nx = x + 1;
    while(ny >= 0 && nx < n) {
        if(chess[ny][nx]) return false;
        ny--;
        nx++;
    }
    return true;
}

void f_queen(int cnt, int n) {
    if(cnt == n) {
        answer++;
        return;
    }
    else {
        for(int i = 0; i < n; i++) {
            if(f_check(cnt, i, n)) {
                chess[cnt][i] = true;
                f_queen(cnt + 1, n);
                chess[cnt][i] = false;
            }
        }
    }
}

int solution(int n) {
    f_queen(0, n);
    return answer;
}