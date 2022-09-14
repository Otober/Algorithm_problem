#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector < pair < int, int > > v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    
    int ans = 0;
    int right = v[0].first;
    for(pair < int, int > iter : v) {
        if(right < iter.second) {
            if(right < iter.first) right = iter.first;
            ans += iter.second - right;
            right= iter.second;
        }
    }
    cout << ans;
    return 0;
}