#include <iostream>
#define N 20

using namespace std;

bool chess[N][N] = {};
int n;
int queen_cnt = 0;

bool check(int cnt, int x) {
    for(int i = 0; i < cnt; i++) {
        if(chess[i][x]) return false;
    }
    int dy = cnt - 1, dx = x - 1;
    while(dy >= 0 && dx >= 0) {
        if(chess[dy][dx]) return false;
        dy--;
        dx--;
    }
    dy = cnt - 1;
    dx = x + 1;
    while(dy >= 0 && dx < n) {
        if(chess[dy][dx]) return false;
        dy--;
        dx++;
    }
    return true;
}

void queen(int cnt) {
    if(cnt == n) {
        queen_cnt++;
        return;
    }
    for(int i = 0; i < n; i++) {
        if(check(cnt,i)) {
            chess[cnt][i] = true;
            queen(cnt + 1);
            chess[cnt][i] = false;
        }
    }
}

int main() {
    
    cin >> n;
    queen(0);
    cout << queen_cnt << "\n";
    return 0;
}