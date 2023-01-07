#include <string>
#include <vector>

using namespace std;

const long long N = 2505;
const long long MOD = 1000000007;

long long dp[N] = {};

int solution(int n) {
    int answer = 0;
    if(n % 2 == 1) answer = 0;
    else {
        dp[1] = 3;
        dp[2] = 11;
        for(int i = 3; i <= n/2; i++) {
            dp[i] = (((4 * dp[i - 1]) - dp[i - 2]) + MOD) % MOD;
        }
    }
    answer = dp[n / 2] % MOD;
    return answer;
}