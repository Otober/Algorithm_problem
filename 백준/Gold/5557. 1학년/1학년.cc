#include <iostream>

using namespace std;

const int N = 105;
const int M = 20;

int n;

int arr[N] = {};

long long dp[N][M + 1] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    dp[1][arr[1]] = 1;
    for(int i = 2; i < n; i++) {
        for(int j = 0; j <= M; j++) {
            if(j + arr[i] <= M) dp[i][j + arr[i]] += dp[i - 1][j];
            if(j - arr[i] >= 0) dp[i][j - arr[i]] += dp[i - 1][j];
        }
    }
    cout << dp[n - 1][arr[n]];
    return 0;
}