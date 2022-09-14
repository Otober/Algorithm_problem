#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, i = 1;
    int ans = 0;
    cin >> n;
    
    while(i <= n) {
        ans += (n - i + 1);
        i *= 10;
    }
    cout << ans;
    return 0;
}