#include <string>
#include <vector>

using namespace std;

const int MOD = 1234567;
const int N = 2005;

long long dp[N] = {};

long long solution(int n) {
    long long answer = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    return answer = dp[n];
}