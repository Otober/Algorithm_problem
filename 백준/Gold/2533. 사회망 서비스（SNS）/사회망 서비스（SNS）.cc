#include <iostream>
#include <algorithm>
#include <vector>
#define N 1000005

using namespace std;

int n;
int dp[N][2];

vector < int > v[N];

int f_dy(int prev, int here, int way) {
    int &ret = dp[here][way];
    
    if(ret != -1) return ret;
    ret = 0;
    
    for(int i = 0; i < v[here].size(); i++) {
        int next = v[here][i];
        if(next == prev) continue;
        
        if(way == 1) ret += f_dy(here, next, 0);
        else ret += max(f_dy(here, next, 1) + 1, f_dy(here, next, 0));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(int i = 0; i <= n; i++) {
        fill_n(dp[i], 2, -1);
    }
    
    cout << n - max(f_dy(-1, 1, 0), f_dy(-1, 1, 1) + 1);
    return 0;
}