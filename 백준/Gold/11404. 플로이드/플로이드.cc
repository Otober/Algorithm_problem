#include <iostream>
#define N 105
#define INT_MAX 987654321

using namespace std;

int n, m;
int arr[N][N] = {};

int f_min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) arr[i][j] = 0;
            else arr[i][j] = INT_MAX;
        }
    }
    
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = f_min(arr[a][b], c);
    }
    
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(arr[i][j] > arr[i][k] + arr[k][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                } 
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(arr[i][j] == INT_MAX) cout << "0" << " ";
            else cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
