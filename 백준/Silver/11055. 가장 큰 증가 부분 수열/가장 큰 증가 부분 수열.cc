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
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++) {
        int temp = 0;
        for(int j = i - 1; j >= 0; j--) {
            if(arr[i] > arr[j]) {
                if(temp < dp[j]) temp = dp[j];
            }
        }
        dp[i] = temp + arr[i];
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(ans < dp[i]) ans = dp[i];
    }
    
    cout << ans;
    return 0;
}