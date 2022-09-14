#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 987654321;

vector < int > v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, s;
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    int low = 0, high = 1;
    int sum = v[0];
    int ans = INF;
    
    while(high < n + 1) {
        if(sum < s) {
            high++;
            sum += v[high - 1];
        }
        else {
            ans = min(ans, high - low);
            low++;
            sum -= v[low - 1];
        }
    }
    if(ans == INF) cout << "0";
    else cout << ans;
    return 0;
}