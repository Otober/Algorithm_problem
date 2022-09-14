#include <iostream>
#include <algorithm>
#include <vector>
#define N 10005

using namespace std;

int n;
int arr[N] = {};
int dp[N][2] = {};

vector < int > v[N];
vector < int > ans;

int f_dfs(int prev, int here, int way) {
    int &ret = dp[here][way];
    if(ret != -1) return ret;
    
    if(way == 1) ret = arr[here];
    else ret = 0;
    
    for(int i = 0; i < v[here].size(); i++) {
        int next = v[here][i];
        if(next == prev) continue;
        
        if(way == 1) ret += f_dfs(here, next, 0);
        else ret += max(f_dfs(here, next, 0), f_dfs(here, next, 1));
    }
    return ret;
}

void f_trace(int prev, int here, int way) {
    if(way == 1) {
        ans.push_back(here);
        for(int i = 0; i < v[here].size(); i++) {
            int next = v[here][i];
            if(next == prev) continue;
            f_trace(here, next, 0);
        }
    }
    else {
        for(int i = 0; i < v[here].size(); i++) {
            int next = v[here][i];
            if(next == prev) continue;
            if(dp[next][1] > dp[next][0]) f_trace(here, next, 1);
            else f_trace(here, next, 0);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        fill_n(dp[i], 2, -1);
    }
    
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    int a = f_dfs(-1, 1, 0);
    int b = f_dfs(-1, 1, 1);
    
    if(a > b) f_trace(-1, 1, 0);
    else f_trace(-1, 1, 1);
    
    sort(ans.begin(), ans.end());
    cout << max(a, b) << "\n";
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}