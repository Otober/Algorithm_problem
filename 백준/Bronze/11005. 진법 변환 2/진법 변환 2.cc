#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, b;
    string ans;
    cin >> n >> b;
    while(n > 0) {
        if(n % b >= 10) ans += (n % b - 10 + 'A');
        else ans += n % b + '0';
        n /= b;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}