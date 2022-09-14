#include <iostream>
#include <vector>

using namespace std;

const int N = 4000005;

bool visit[N] = {};

vector < int > v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int ans = 0;
    cin >> n;
    for(int i = 2; i <= n / 2; i++) {
        for(int j = 2; j * i <= n; j++) {
            visit[i * j] = true;
        }
    }
    for(int i = 2; i <= n; i++) {
        if(!visit[i]) v.push_back(i);
    }
    
    if(v.size() != 0) {
        int low = 0, high = 1;
        int sum = v[0];
        while(high < v.size() + 1) {
            if(sum < n) {
                high++;
                sum += v[high - 1];
            }
            else if(sum > n) {
                low++;
                sum -= v[low - 1];
            }
            else {
                ans++;
                low++;
                sum -= v[low - 1];
                high++;
                sum += v[high - 1];
            }
        }
    }
    cout << ans;
    return 0;
}