#include <iostream>
#define N 105
#define M 100005

using namespace std;

int dp[N][M] = {};

struct Object {
    int w,v;
}arr[N];

int f_max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n,k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].w >> arr[i].v;
    }
    
    for(int i = 1; i <=n; i++) {
        for(int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];
            if(j - arr[i].w >= 0) {
                dp[i][j] = f_max(dp[i][j], dp[i - 1][j - arr[i].w] + arr[i].v);
            }
        }
    }
    cout << dp[n][k];
    return 0;
}