#include <iostream>
#define N 15

using namespace std;

int arr[N] = {};

int main() {
    int n,k;
    int cnt = 0;
    int temp;
    cin >> n >> k;
    temp = n - 1;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    while(k) {
        while(arr[temp] <= k) {
            k -= arr[temp];
            cnt++;
        }
        temp--;
    }
    cout << cnt;
    return 0;
}