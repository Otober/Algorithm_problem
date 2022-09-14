#include <iostream>
#include <algorithm>

using namespace std;

const int N = 55;

int n;
int ans = 0;

char board[N][N] = {};

void f_compare(int y, int x) {
    int cnt;
    int ty, tx;
    
    ty = y;
    tx = x;
    cnt = 1;
    while(ty < n - 1) {
        if(board[ty][tx] != board[ty + 1][tx]) break;
        cnt++;
        ty++;
    }
    ty = y;
    tx = x;
    while(ty > 0) {
        if(board[ty][tx] != board[ty - 1][tx]) break;
        cnt++;
        ty--;
    }
    ans = max(ans, cnt);
    
    cnt = 1;
    ty = y;
    tx = x;
    while(tx < n - 1) {
        if(board[ty][tx] != board[ty][tx + 1]) break;
        cnt++;
        tx++;
    }
    ty = y;
    tx = x;
    while(tx > 0) {
        if(board[ty][tx] != board[ty][tx - 1]) break;
        cnt++;
        tx--;
    }
    ans = max(ans, cnt);
}

void f_check(int y, int x) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            f_compare(i, j);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(j < n - 1) {
                swap(board[i][j], board[i][j + 1]);
                f_check(i, j);
                swap(board[i][j], board[i][j + 1]);
            }
            if(i < n - 1) {
                swap(board[i][j], board[i + 1][j]);
                f_check(i, j);
                swap(board[i][j], board[i + 1][j]);
            }
        }
    }
    cout << ans;
    return 0;
}