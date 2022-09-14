#include <iostream>
#define N 20
#define INF 987654321

using namespace std;

int arr[N][N] = {};
int dp[N][1 << N] = {};
int ans = INF;
int n;

int f_min(int a, int b) {
    return a < b ? a : b;
}

int tsp(int cur, int visit) {
    if(visit == (1 << n) - 1) {
        if(arr[cur][0] == 0) return INF;
        else return arr[cur][0];
    }
    if(dp[cur][visit] != 0) return dp[cur][visit];
    
    int temp = INF;
    for(int i = 1; i < n; i++) {
        if(((visit & (1 << i)) == 0) && (arr[cur][i] != 0)) {
            temp = f_min(temp, tsp(i, (visit | (1 << i))) + arr[cur][i]);
        }
    }
    dp[cur][visit] = temp;
    return dp[cur][visit];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    cout << tsp(0, 1) << endl;
    
    return 0;
}