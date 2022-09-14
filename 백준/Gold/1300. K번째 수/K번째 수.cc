#include <iostream>

using namespace std;

int f_min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    int low = 1, high = k;
    int ans = 0;
    
    while(low <= high) {
        int mid = (low + high) / 2;
        int cnt = 0;
        for(int i = 1; i <= n; i++) cnt += f_min(n, mid / i);
        if(cnt < k) low = mid + 1;
        else {
            ans = mid;
            high = mid - 1;
        }
    }
    cout << ans;
    return 0;
}