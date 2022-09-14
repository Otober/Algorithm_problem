#include <iostream>
#define N 10

using namespace std;

int n,m;
int arr[N] = {};

void dfs(int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 1; i <= n; i++) { 
        arr[cnt] = i;
        dfs(cnt + 1);
    }
}

int main() {
    cin >> n >> m;
    dfs(0);
    return 0;
}