#include <iostream>
#define N 100005

using namespace std;

int arr[N] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    
    while(m--) {
        int left, right;
        cin >> left >> right;
        cout << arr[right] - arr[left - 1] << "\n";
    }
    return 0;
}