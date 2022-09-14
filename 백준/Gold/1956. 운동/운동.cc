#include <iostream>
#define N 405
#define INF 987654321

using namespace std;

int f_min(int a, int b) {
    return a < b ? a : b;
}

int arr[N][N] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int v, e;
    cin >> v >> e;
    for(int i = 1; i <= v; i++) {
        for(int j = 1; j <= v; j++) {
            arr[i][j] = INF;
        }
    }
    for(int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = c;
    }
    
    for(int k = 1; k <= v; k++) {
        for(int i = 1; i <= v; i++) {
            for(int j = 1; j <= v; j++) {
                if(arr[i][j] > arr[i][k] + arr[k][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
    
    int ans = INF;
    for(int i = 1; i <= v; i++) {
        for(int j = 1; j <= v; j++) {
            if(i == j) continue;
            if(arr[i][j] != INF && arr[j][i] != INF) {
                ans = f_min(ans, arr[i][j] + arr[j][i]);
            }
        }
    }
    
    if(ans == INF) cout << "-1" << endl;
    else cout << ans << endl;
    return 0;
}