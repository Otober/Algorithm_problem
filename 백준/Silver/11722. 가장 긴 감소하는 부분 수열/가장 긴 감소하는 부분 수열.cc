#include <iostream>

using namespace std;

const int N = 1005;

int dp[N] = {};
int arr[N] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = n - 1; i >= 0; i--) {
        cin >> arr[i];
    }
    
    for(int i = 0; i < n; i++) {
        int temp = 0;
        for(int j = i - 1; j >= 0; j--) {
            if(arr[i] > arr[j]) {
                if(temp < dp[j]) temp = dp[j];
            }
        }
        dp[i] = temp + 1;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(dp[i] > ans) ans = dp[i];
    }
    cout << ans;
    return 0;
}