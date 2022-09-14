#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int ans = 0;
        int ytemp = 0;
        int m, n, x, y;
        
        cin >> m >> n >> x >> y;
        
        int lcm = m * n / gcd(m, n);
        ans += x;
        ytemp += x;
        while(ytemp > n) {
            ytemp -= n;
        }
        if(ytemp != y) {
            while(ans <= lcm) {
                ytemp += m;
                while(ytemp > n) {
                    ytemp -= n;
                }
                ans += m;
                if(ytemp == y) break;
            }
        }
        if(ans <= lcm) cout << ans << "\n";
        else cout << "-1" << "\n";
    }
    return 0;
}