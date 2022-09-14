#include <iostream>
#include <algorithm>
#define N 10

using namespace std;

int n, m;
int arr[N] = {};
int ans[N] = {};

void f_dfs(int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i = 0; i < n; i++) {
        ans[cnt] = arr[i];
        f_dfs(cnt + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    f_dfs(0);
    return 0;
}