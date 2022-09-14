#include <iostream>
#include <algorithm>
#define N 55

using namespace std;

int main() {
    int n;
    long long int arr[N] = {};
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cout << arr[0] * arr[n - 1];
    return 0;
}