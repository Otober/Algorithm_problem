#include <iostream>

using namespace std;

const int N = 35;

int dp[N] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    if(n % 2 == 1) cout << "0";
    else {
        dp[0] = 1;
        for(int i = 2; i <= n; i += 2) {
            for(int j = i - 2; j >= 0; j -= 2) {
                dp[i] += dp[j] * 2;
            }
            dp[i] += dp[i - 2];
        }
        cout << dp[n];
    }
    return 0;
}