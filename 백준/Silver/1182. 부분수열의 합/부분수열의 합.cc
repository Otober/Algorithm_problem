#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, s;
int ans = 0;

vector < int > v;

void f_dfs(int idx, int sum) {
    sum += v[idx];
    if(idx >= n) return;
    if(sum == s) ans++;
    
    f_dfs(idx + 1, sum);
    f_dfs(idx + 1, sum - v[idx]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        int temp;
        cin>> temp;
        v.push_back(temp);
    }
    f_dfs(0, 0);
    cout << ans;
    return 0;
}