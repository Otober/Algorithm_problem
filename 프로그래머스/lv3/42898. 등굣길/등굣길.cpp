#include <string>
#include <vector>

using namespace std;

const int N = 105;
const int devive = 1000000007;
long long dp[N][N] = {};
bool map[N][N] = {};

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    dp[1][0] = 1;
    for(int i = 0; i < puddles.size(); i++) {
        map[puddles[i][1]][puddles[i][0]] = true;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(map[i][j] == true) continue;
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % devive;
        }
    }
    answer = dp[n][m];
    return answer;
}