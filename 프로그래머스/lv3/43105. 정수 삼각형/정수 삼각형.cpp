#include <string>
#include <vector>

using namespace std;

const int N = 505;

int dp[N][N] = {};

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    dp[0][0] = triangle[0][0];
    for(int i = 1; i < triangle.size(); i++) {
        for(int j = 0; j < triangle[i].size(); j++) {
            if(dp[i][j] < dp[i - 1][j - 1] + triangle[i][j]) dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            if(dp[i][j] < dp[i - 1][j] + triangle[i][j]) dp[i][j] = dp[i - 1][j] + triangle[i][j];
            if(answer < dp[i][j]) answer = dp[i][j];
        }
    }
    return answer;
}