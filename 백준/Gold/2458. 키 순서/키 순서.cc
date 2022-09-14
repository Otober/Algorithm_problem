#include <iostream>
#include <algorithm>

using namespace std;

const int N = 505;
const int INF = 100;

int n, m;
int ans = 0;

int arr[N][N] = {};

void f_initialize() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            arr[i][j] = (i == j) ? 0 : INF;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    f_initialize();
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j) continue;
                arr[i][j] = min(arr[i][j], max(arr[i][k], arr[k][j]));
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        for(int j = 1; j <= n; j++) {
            if(arr[i][j] == 1) cnt++;
            if(arr[j][i] == 1) cnt++;
        }
        if(n - 1 == cnt) ans++;
    }
    cout << ans;
    return 0;
}