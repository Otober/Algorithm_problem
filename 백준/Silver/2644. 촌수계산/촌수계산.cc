#include <iostream>

using namespace std;

const int N = 105;

bool flag = false;

int ans = 0;

bool visit[N] = {};

int arr[2];
int parents[N] = {};
int relation[N] = {};

void f_dfs(int node, int cnt) {
    relation[node] += cnt;
    if(visit[node]) {
        ans = relation[node];
        flag = true;
        return;
    }
    else {
        visit[node] = true;
        if(parents[node] != 0) f_dfs(parents[node], cnt + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    int a, b;
    cin >> n;
    cin >> arr[0] >> arr[1];
    cin >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        parents[y] = x;
    }
    
    for(int k = 0; k < 2; k++) {
        f_dfs(arr[k], 0);
    }
    if(flag) cout << ans;
    else cout << "-1";
    return 0;
}