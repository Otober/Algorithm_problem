#include <iostream>
#include <queue>
#define INF 987654321
#define N 1005

using namespace std;

int dp[2 * N][2 * N] = {};
priority_queue < pair < int, pair < int, int > > > pq;

void f_initialize() {
    pq.push(make_pair(-0, make_pair(1, 0)));
    for(int i = 0; i < N; i++) {
        fill_n(dp[i], N, INF);
    }
    dp[1][0] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    f_initialize();
    
    while(!pq.empty()) {
        int cnt = -pq.top().first;
        int screen = pq.top().second.first;
        int clipboard = pq.top().second.second;
        pq.pop();
        
        if(screen == n) {
            cout << cnt;
            break;
        }
        
        if(clipboard > 0) {
            if(dp[screen + clipboard][clipboard] > cnt + 1) {
                dp[screen + clipboard][clipboard] = cnt + 1;
                pq.push(make_pair(-(cnt + 1), make_pair(screen + clipboard, clipboard)));
            }
        }
        if(dp[screen][screen] > cnt + 1) {
            dp[screen][screen] = cnt + 1;
            pq.push(make_pair(-(cnt + 1), make_pair(screen, screen)));
        }
        if(screen > 0) {
            if(dp[screen - 1][clipboard] > cnt + 1) {
                dp[screen - 1][clipboard] = cnt + 1;
                pq.push(make_pair(-(cnt + 1), make_pair(screen - 1, clipboard)));
            }
        }
    }
    return 0;
}