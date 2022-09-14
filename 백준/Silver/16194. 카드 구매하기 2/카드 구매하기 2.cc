#include <iostream>
#define N 1005

using namespace std;

int dp[N] = {};
int arr[N] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }
    
    for(int i = 2; i <= n; i++) {
        int low = 1;
        int high = i - 1;
        while(low <= high) {
            if(dp[i] > dp[low] + dp[high]) {
                dp[i] = dp[low] + dp[high];
            }
            low++;
            high--;
        }
    }
    cout << dp[n];
    return 0;
}