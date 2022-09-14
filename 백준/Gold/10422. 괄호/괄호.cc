#include <iostream>

using namespace std;

const int N = 5005;
const long long devive = 1000000007;

long long dp[N] = {};

void f_initialize() {
    dp[0] = 1;
    dp[2] = 1;
    for(int i = 3; i < N; i++) {
        for(int j = 2; j <= i; j++) {
            dp[i] += (dp[j - 2] * dp[i - j]) % devive;
        }
        dp[i] %= devive;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    f_initialize();
    while(t--) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}