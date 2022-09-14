#include <iostream>
#define N 105

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
        int n;
        long long ans = 0;
        int arr[N] = {};
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                ans += f_gcd(arr[i], arr[j]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}