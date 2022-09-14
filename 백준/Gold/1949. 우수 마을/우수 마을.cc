#include <iostream>
#include <algorithm>
#include <vector>
#define N 10005

using namespace std;

int n;
int arr[N] = {};
int dp[N][2] = {};

vector < int > v[N];

int f_dy(int prev, int here, int way) {
    int &ret = dp[here][way];
    
    if(ret != -1) return ret;
    
    if(way == 1) ret = arr[here];
    else ret = 0;
    
    for(int i = 0; i < v[here].size(); i++) {
        int next = v[here][i];
        if(prev == next) continue;
        if(way == 1) ret += f_dy(here, next, 0);
        else ret += max(f_dy(here, next, 0), f_dy(here, next, 1));
    }
    return ret;
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
    
    cout << max(f_dy(-1, 1, 0), f_dy(-1, 1, 1));
    return 0;
}