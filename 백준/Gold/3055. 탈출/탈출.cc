#include <iostream>
#include <queue>
#define N 55
#define INF 987654321

using namespace std;

int r, c;
int water = 0;
int hedgehog = 0;
int dp[N][N] = {};
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
bool flag = false;
char arr[N][N] = {};
queue < pair < int, int > > q;
queue < pair < int, int > > pq;

bool f_check(int y, int x) {
    if(y < 0 || y >= r) return false;
    if(x < 0 || x >= c) return false;
    if(arr[y][x] == 'X') return false;
    if(arr[y][x] == '*') return false;
    return true;
}

void f_flood() {
    int tcnt = 0;
    while(water--) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(f_check(ny, nx)) {
                if(arr[ny][nx] != 'D') {
                    q.push(make_pair(ny, nx));
                    arr[ny][nx] = '*';
                    tcnt++;
                }
            }
        }
    }
    water = tcnt;
}

void f_move() {
    int temp = 0;
    while(hedgehog--) {
        int y = pq.front().first;
        int x = pq.front().second;
        pq.pop();
    
        if(arr[y][x] == 'D') {
            flag = true;
            cout << dp[y][x];
            return;
        }
    
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(f_check(ny, nx)) {
                if(dp[ny][nx] > dp[y][x] + 1) {
                    dp[ny][nx] = dp[y][x] + 1;
                    pq.push(make_pair(ny, nx));
                    temp++;
                }
            }
        }
    }
    hedgehog = temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> arr[i][j];
            dp[i][j] = INF;
            if(arr[i][j] == 'S') {
                dp[i][j] = 0;
                pq.push(make_pair(i, j));
                hedgehog++;
            }
            if(arr[i][j] == '*') {
                q.push(make_pair(i ,j));
                water++;
            }
        }
    }
    
    while(!pq.empty()) {
        f_flood();
        f_move();
        if(flag == true) break;
    }
    if(flag == false) cout << "KAKTUS";
    return 0;
}