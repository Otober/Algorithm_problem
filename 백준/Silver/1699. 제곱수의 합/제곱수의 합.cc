#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100005;

int dp[N] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        dp[i] = i;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 2; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - (j * j)] + 1);
        }
    }
    cout << dp[n];
    return 0;
}