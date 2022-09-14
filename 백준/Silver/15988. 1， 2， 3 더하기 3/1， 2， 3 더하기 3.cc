#include <iostream>
#define N 1000000
#define devive 1000000009

using namespace std;

long long arr[N] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        arr[0] = 1;
        arr[1] = 1;
        arr[2] = 2;
        
        for(int i = 3; i <= n; i++) {
            arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 3]) % devive;
        }
        cout << arr[n] << "\n";
    }
    return 0;
}