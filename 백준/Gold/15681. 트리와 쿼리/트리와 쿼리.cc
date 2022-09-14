#include <iostream>
#include <vector>
#define N 100005

using namespace std;
int ans[N] = {};

vector <int > v[N];

int f_dfs(int here, int prev) {
    ans[here] = 1;
    for(int i = 0; i < v[here].size(); i++) {
        int next = v[here][i];
        if(prev == next) continue;
        ans[here] += f_dfs(next, here);
    }
    return ans[here];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, r, q;
    cin >> n >> r >> q;
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    f_dfs(r, 0);
    while(q--) {
        int temp;
        cin >> temp;
        cout << ans[temp] << "\n";
    }
    return 0;
}