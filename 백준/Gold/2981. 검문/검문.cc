#include <iostream>
#include <algorithm>
#define N 105

using namespace std;

int arr[N] = {};
int ans[5 * N] = {};

int gcd(int a, int b) {
    return a % b ? gcd(b, a % b) : b;
}

int main() {
    int n;
    int m;
    int cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    m = arr[1] - arr[0];
    for(int i = 2; i < n; i++) {
        m = gcd(m,arr[i] - arr[i - 1]);
    }
    
    for(int i = 1; i * i <= m; i++) {
        if(m % i == 0) {
            ans[cnt++] = i;
            if(i != m / i) ans[cnt++] = m / i;
        }
    }
    
    sort(ans, ans + cnt);
    for(int i = 0; i < cnt; i++) {
        if(ans[i] != 1) cout << ans[i] << " ";
    }
    return 0;
}