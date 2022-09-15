#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;
const int N = 100005;

long long dp[N] = {};

int solution(int n, vector<int> money) {
    int answer = 0;    
    dp[0] = 1;
    for(int i = money[0]; i <= n; i += money[0]) {
        dp[i] = 1;
    }
    for(int i = 1; i < money.size(); i++) {
        for(int j = 0; j <= n; j++) {
            if(j >= money[i]) dp[j] += dp[j - money[i]];
        }
    }
    return answer = dp[n];
}