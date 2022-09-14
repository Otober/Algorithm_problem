#include <iostream>
#define N 200005
#define K 19

using namespace std;

int arr[N][K] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m, q;
    cin >> m;
    for(int i = 1; i <= m; i++) {
        cin >> arr[i][0];
    }
    for(int j = 1; j < K; j++) {
        for(int i = 1; i <= m; i++) {
            arr[i][j] = arr[arr[i][j - 1]][j - 1];
        }
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        int n, x;
        cin >> n >> x;
        for(int i = 0; n; i++) {
            if(n & 1) x = arr[x][i];
            n = n >> 1;
        }
        cout << x << "\n";
    }
    return 0;
}