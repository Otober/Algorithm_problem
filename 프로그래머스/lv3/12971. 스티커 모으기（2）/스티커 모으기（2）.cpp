#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100005;

int dp[N][2] = {};

int solution(vector<int> sticker)
{
    int answer = 0;
    int n = sticker.size();
    for(int k = 0; k < 2; k++) {
        dp[k][k] = sticker[k];
        if(k == 0) dp[1][k] = dp[0][k];
        for(int i = 2; i < n - 1; i++) {
            dp[i][k] = max(dp[i - 1][k], dp[i - 2][k] + sticker[i]);
        }
        if(k == 0) dp[n - 1][k] = dp[n - 2][k];
        else dp[n - 1][k] = max(dp[n - 2][k], dp[n - 3][k] + sticker[n - 1]);
        answer = max(answer, dp[n - 1][k]);
    }
    return answer;
}