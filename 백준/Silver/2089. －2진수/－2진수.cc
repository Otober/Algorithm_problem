#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    int n;
    cin >> n;
    if(n == 0) cout << "0";
    else {
        string ans;
        while(n != 0) {
            if(n % -2 == 0) {
                ans += '0';
                n /= -2;
            }
            else {
                ans += '1';
                n = (n - 1) / -2;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
    return 0;
}