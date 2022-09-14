#include <iostream>

using namespace std;

int f_gcd(int a, int b) {
    return (b == 0) ? a : f_gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        int gcd = f_gcd(a, b);
        cout << a * b / gcd << "\n";
    }
    return 0;
}