#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector < int > v;
vector < int > vt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
        vt.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int it : vt) {
        cout << lower_bound(v.begin(), v.end(), it) - v.begin() << " ";
    }
    return 0;
}