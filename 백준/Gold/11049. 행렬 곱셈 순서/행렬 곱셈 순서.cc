#include <iostream>
#include <climits>
#define N 505

using namespace std;

struct matrix{
    int r, c;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    int dp[N][N] = {};
    matrix arr[N][N];
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i][i].r >> arr[i][i].c;
    }
    
    for(int i = 2; i <= n; i++) {
        int dx = i;
        int dy = 1;
        while(dx <= n) {
            dp[dy][dx] = INT_MAX;
            for(int k = dy; k < dx; k++) {
                int temp = dp[dy][k] + dp[k + 1][dx] + (arr[dy][k].r * arr[dy][k].c * arr[k + 1][dx].c);
                if(dp[dy][dx] > temp) {
                    dp[dy][dx] = temp;
                    arr[dy][dx].r = arr[dy][k].r;
                    arr[dy][dx].c = arr[k + 1][dx].c;
                }
            }
            dx++;
            dy++;
        }
    }
    cout << dp[1][n];
    return 0;
}