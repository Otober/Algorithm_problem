#include <iostream>
#define N 105

using namespace std;

int dp[N * N] = {};
int arr[N] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    dp[0] = 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(j >= arr[i]) {
                dp[j] += dp[j - arr[i]];
            }
        }
    }
    
    cout << dp[k];
    return 0;
}