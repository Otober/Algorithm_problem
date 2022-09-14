#include <iostream>
#include <queue>
#include <string>
#define N 1005

using namespace std;

int n, m;
int arr[N][N] = {};
int visit[N][N][2] = {};
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
queue < pair < pair < int, int >, int > >q;

bool check(int y, int x) {
    if(y < 1 || y > n) return false;
    if(x < 1 || x > m) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        string temp;
        cin >> temp;
        for(int j = 1; j <= m; j++) {
            arr[i][j] = temp[j - 1] - '0';
        }
    }
    
    q.push(make_pair(make_pair(1, 1), 1));
    visit[1][1][1] = 1;
    
    while(!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int b = q.front().second;
        if(y == n && x == m) {
            cout << visit[y][x][b];
            break;
        }
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(check(ny, nx)) {
                if(b && (arr[ny][nx] == 1)) {
                    visit[ny][nx][b - 1] = visit[y][x][b] + 1;
                    q.push(make_pair(make_pair(ny, nx), b - 1));
                }
                else if(arr[ny][nx] == 0 && visit[ny][nx][b] == 0) {
                    visit[ny][nx][b] = visit[y][x][b] + 1;
                    q.push(make_pair(make_pair(ny, nx), b));
                }
            }
        }
    }
    if(q.empty()) cout << "-1";
    return 0;
}