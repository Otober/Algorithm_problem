#include <iostream>
#define N 2005

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, t;
    int arr[N] = {};
    bool dp[N][N] = {};
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i][i] = true;
    }
    for(int i = 1; i < n; i++) {
        if(arr[i] == arr[i + 1]) dp[i][i + 1] = true;
    }
    
    for(int i = 2; i < n; i++) {
        for(int j = 1; j <= n - i; j++) {
            if(arr[j] == arr[i + j] && dp[j + 1][i + j - 1]) dp[j][i + j] = true;
        }
    }
    cin >> t;
    while(t--) {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << "\n";
    }
    return 0;
}