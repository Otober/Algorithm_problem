#include <iostream>
#define N 105

using namespace std;

int arr1[N][N] = {}, arr2[N][N] = {};
int arr[N][N] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> arr1[i][j];
        }
    }
    
    cin >> m >> k;
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= k; j++) {
            cin >> arr2[i][j];
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            for(int t = 1; t <= m; t++) {
                arr[i][j] += arr1[i][t] * arr2[t][j];
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}