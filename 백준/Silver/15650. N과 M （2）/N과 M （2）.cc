#include <iostream>
#define N 10

using namespace std;

int n,m;
int arr[N] = {};
bool visit[N] = {};

void dfs(int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m - 1; i++) {
            if(arr[i] > arr[i + 1]) return;
        }
        
        for(int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!visit[i]) {
            visit[i] = true;
            arr[cnt] = i;
            dfs(cnt + 1);
            visit[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    dfs(0);
    return 0;
}