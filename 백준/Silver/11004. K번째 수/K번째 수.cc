#include <iostream>
#include <algorithm>
#define N 5000005

using namespace std;

int arr[N] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cout << arr[k - 1];
    return 0;
}