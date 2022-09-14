#include <iostream>
#define N 20
#define INF 20000000

using namespace std;

int n;
int ans = INF;
int visit[N] = {};
int arr[N][N] = {};

int f_min(int &a, int &b) {
    return a < b ? a : b;
}

void f_dfs(int cnt, int sum, int start, int now) {
    if(cnt == n - 1) {
        if(arr[now][start] != 0) {
            sum += arr[now][start];
            ans = f_min(ans, sum);
        }
        return;
    }
    
    visit[now] = true;
    for(int i = 0; i < n; i++) {
        if(!visit[i] && arr[now][i] != 0) {
            f_dfs(cnt + 1, sum + arr[now][i], start, i);
        }
    }
    visit[now] = false;
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
    
    for(int i = 0; i < n; i++) {
        f_dfs(0, 0, i, i);
    }
    cout << ans;
    return 0;
}