#include <iostream>
#include <vector>
#define N 2005

using namespace std;

int n, m;
bool flag = false;
bool visit[N] = {};
vector < int > v[N];

void f_dfs(int node, int cnt) {
    if(cnt == 5) {
        cout << "1";
        flag = true;
        return;
    }
    
    visit[node] = true;
    for(int i = 0; i < v[node].size(); i++) {
        int next = v[node][i];
        if(visit[next]) continue;
        f_dfs(next, cnt + 1);
        if(flag == true) return;
    }
    visit[node] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(int i = 0; i < n; i++) {
        f_dfs(i, 1);
        if(flag) break;
        if(i == n - 1) cout << "0";
    }
    return 0;
}