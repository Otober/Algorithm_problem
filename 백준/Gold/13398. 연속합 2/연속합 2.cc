#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100005;
const int INF = 987654321;

int arr[N] = {};

int dp[N][2] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dp[0][0] = dp[0][1] = -INF;
    int ans = -INF;
    for(int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
        ans = max(ans,max(dp[i][0], dp[i][1]));
    }
    cout << ans;
    return 0;
}