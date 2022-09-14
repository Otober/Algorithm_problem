#include <iostream>
#include <algorithm>
#include <vector>
#define N 500005

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    vector < int > v;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    
    cin >> m;
    for(int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        vector< int >::iterator high = lower_bound(v.begin(), v.end(), temp + 1);
        vector< int >::iterator low = lower_bound(v.begin(), v.end(), temp);
        cout << high - low << " ";
    }
    return 0;
}