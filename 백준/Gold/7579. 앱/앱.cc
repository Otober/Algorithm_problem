#include <iostream>
#include <climits>
#define N 105

using namespace std;

int dp[N][N * N] = {};
int memory[N] = {};
int cost[N] = {};
int result = INT_MAX;

int f_max(int a, int b) {
    return a > b ? a : b;
}
int f_min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> memory[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= N * N; j++) {
            dp[i][j] = dp[i - 1][j];
            if(j - cost[i] >= 0) {
                dp[i][j] = f_max(dp[i][j], dp[i - 1][j - cost[i]] + memory[i]);
            }
            if(dp[i][j] >= k) result = f_min(result, j);
        }
    }
    cout << result;
    return 0;
}