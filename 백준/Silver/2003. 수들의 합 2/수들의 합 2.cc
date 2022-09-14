#include <iostream>
#include <vector>

using namespace std;

vector < int > v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    
    int ans = 0;
    int low = 0, high = 1;
    int sum = v[0];
    while(low <= high && high < n + 1) {
        if(sum < m) {
            high++;
            sum += v[high - 1];
        }
        else if(sum > m) {
            low++;
            sum -= v[low - 1];
        }
        else {
            ans++;
            high++;
            sum += v[high - 1];
            low++;
            sum -= v[low - 1];
        }
    }
    cout << ans;
    return 0;
}