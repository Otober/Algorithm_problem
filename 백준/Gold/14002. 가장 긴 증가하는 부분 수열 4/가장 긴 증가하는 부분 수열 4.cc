#include <iostream>
#define N 1005
#define INF 987654321

using namespace std;

int arr[N] = {};
int dp[N] = {};
int before[N] = {};

void f_print(int n) {
    if(n == -1) return;
    f_print(before[n]);
    cout << arr[n] << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = 1;
        before[i] = -1;
        
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                before[i] = j;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i < n ; i++) {
        if(dp[ans] < dp[i]) ans = i;
    }
    cout << dp[ans] << endl;
    f_print(ans);
    return 0;
}