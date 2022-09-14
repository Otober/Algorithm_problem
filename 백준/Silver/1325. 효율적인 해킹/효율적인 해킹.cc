#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 10005;

int n, m;
int cnt = 0;
int tmax = 0;

bool visit[N] = {};

vector < int > ans;

vector < int > v[N];

void f_dfs(int node) {
    visit[node] = true;
    for(int i = 0; i < v[node].size(); i++) {
        if(!visit[v[node][i]]) {
            cnt++;
            f_dfs(v[node][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }
    
    for(int i = 1; i <= n; i++) {
        fill_n(visit, N, false);
        cnt = 0;
        f_dfs(i);
        if(tmax < cnt) {
            tmax = cnt;
            ans.clear();
            ans.push_back(i);
        }
        else if(tmax == cnt) ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    for(vector < int >::iterator iter = ans.begin(); iter != ans.end(); iter++) {
        cout << *iter << " ";
    }
    return 0;
}