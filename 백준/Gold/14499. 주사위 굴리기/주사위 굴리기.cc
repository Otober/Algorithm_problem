#include <iostream>

using namespace std;

const int N = 25;
const int dy[5] = {0, 0, 0, -1, 1};
const int dx[5] = {0, 1, -1, 0, 0};

int y, x;
int n, m, k;

int dice[4][3] = {};
int board[N][N] = {};

void f_north() {
    int temp = dice[0][1];
    dice[0][1] = dice[1][1];
    dice[1][1] = dice[2][1];
    dice[2][1] = dice[3][1];
    dice[3][1] = temp;
}

void f_south() {
    for(int i = 0; i < 3; i++) {
        f_north();
    }
}

void f_east() {
    int temp = dice[1][1];
    dice[1][1] = dice[1][0];
    dice[1][0] = dice[3][1];
    dice[3][1] = dice[1][2];
    dice[1][2] = temp;
}

void f_west() {
    for(int i = 0; i < 3; i++) {
        f_east();
    }
}

bool f_check(int y, int x) {
    if(y < 0 || y >= n) return false;
    if(x < 0 || x >= m) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> y >> x >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    
    while(k--) {
        int dir;
        cin >> dir;
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(f_check(ny, nx)) {
            y = ny;
            x = nx;
            switch(dir) {
                case 1 : f_east(); break;
                case 2 : f_west(); break;
                case 3 : f_north(); break;
                case 4 : f_south(); break;
            }
            if(board[y][x] == 0) board[y][x] = dice[3][1];
            else {
                dice[3][1] = board[y][x];
                board[y][x] = 0;
            }
            cout << dice[1][1] << "\n";
        }
    }
    return 0;
}