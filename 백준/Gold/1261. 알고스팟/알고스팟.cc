#include <iostream>
#include <queue>
#include <string>
#define N 105
#define INF 987654321

using namespace std;

int n, m;
int dp[N][N] = {};
int arr[N][N] = {};
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
priority_queue < pair < int, pair < int, int > > > pq;

bool f_check(int y, int x) {
    if(y < 1 || y > n) return false;
    if(x < 1 || x > m) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> m >> n;
    for(int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        for(int j = 1; j <= m; j++) {
            arr[i][j] = str[j - 1] - '0';
            dp[i][j] = INF;
        }
    }
    
    dp[1][1] = 0;
    pq.push(make_pair(-0, make_pair(1, 1)));
    
    while(!pq.empty()) {
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(f_check(ny, nx)) {
                if(arr[ny][nx] == 1) {
                    if(dp[y][x] + 1 < dp[ny][nx]) {
                        dp[ny][nx] = dp[y][x] + 1;
                        pq.push(make_pair(-dp[ny][nx], make_pair(ny, nx)));
                    }
                }
                else {
                    if(dp[y][x] < dp[ny][nx]) {
                        dp[ny][nx] = dp[y][x];
                        pq.push(make_pair(-dp[ny][nx], make_pair(ny, nx)));
                    }
                }
            }
        }
    }
    cout << dp[n][m];
    return 0;
}