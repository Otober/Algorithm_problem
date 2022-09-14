#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1005;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        int dp[N] = {};
        vector < int > v;
        fill_n(dp, N, 0);
        
        cin >> n;
        for(int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        dp[0] = v[0];
        for(int i = 1; i < n; i++) {
            dp[i] = max(0, dp[i - 1]) + v[i];
        }
        int ans = -987654321;
        for(int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}