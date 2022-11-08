#include <string>
#include <vector>

using namespace std;

const int N = 1000005;

long long int dp[N][2] = {};

int solution(vector<int> money) {
    int answer = 0;
    dp[1][0] = money[1];
    for(int i = 2; i < money.size(); i++) {
        dp[i][0] = max(dp[i - 2][0] + money[i], dp[i - 1][0]);
    }
    
    dp[0][1] = money[0];
    dp[1][1] = money[0];
    for(int i = 2; i < money.size() - 1; i++) {
        dp[i][1] = max(dp[i - 2][1] + money[i], dp[i - 1][1]);
    }
    answer = max(dp[money.size() - 1][0], dp[money.size() - 2][1]);
    return answer;
}