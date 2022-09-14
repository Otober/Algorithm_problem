#include <iostream>
#include <algorithm>

using namespace std;

const int N = 105;

long long dp[N] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 1; i <= 6; i++) {
        dp[i] = i;
    }
    
    for(int i = 7; i <= n; i++) {
        for(int j = 1; j <= i - 3; j++) {
            dp[i] = max(max(dp[i - 1] + 1, (dp[i - (j + 2)] * (j + 1))), dp[i]);
        }
    }
    cout << dp[n];
    return 0;
}