#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10;

bool possible[N] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    fill_n(possible, N, true);
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        possible[t] = false;
    }
    
    int ans = abs(n - 100);
    for(int i = 0; i <= 888888; i++) {
        int cnt = 0;
        int temp = i;
        bool flag = true;
        while(temp > 0) {
            if(possible[temp % 10] == false) {
                flag = false;
                break;
            }
            temp /= 10;
            cnt++;
        }
        if(i == 0) {
            if(possible[0] == false) flag = false;
            else {
                flag = true;
                cnt = 1;
            }
        }
        if(flag == false) continue;
        ans = min(ans, abs(n - i) + cnt);
    }
    cout << ans;
    return 0;
}