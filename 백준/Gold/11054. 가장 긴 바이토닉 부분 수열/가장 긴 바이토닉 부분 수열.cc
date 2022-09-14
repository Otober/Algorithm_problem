#include <iostream>

using namespace std;

const int N = 1005;

int arr[N] = {};
int increase_dp[N] = {};
int decrease_dp[N] = {};

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
                if(temp < increase_dp[j]) temp = increase_dp[j];
            }
        }
        increase_dp[i] = temp + 1;
    }
    
    for(int i = n - 1; i >= 0; i--) {
        int temp = 0;
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                if(temp < decrease_dp[j]) temp = decrease_dp[j];
            }
        }
        decrease_dp[i] = temp + 1;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(ans < increase_dp[i] + decrease_dp[i] - 1) ans = increase_dp[i] + decrease_dp[i] - 1;
    }
    cout << ans;
    return 0;
}