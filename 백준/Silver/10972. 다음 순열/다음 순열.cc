#include <iostream>
#include <algorithm>
#define N 100005

using namespace std;

int arr[N] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int idx = -1;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for(int i = n; i > 0; i--) {
        if(arr[i - 1] < arr[i]) {
            idx = i;
            break;
        }
    }
    if(idx == -1) cout << "-1";
    else {
        for(int i = n - 1; i >= idx; i--) {
            if(arr[idx - 1] < arr[i]) {
                swap(arr[idx - 1], arr[i]);
                break;
            }
        }
        sort(arr + idx, arr + n);
        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
    }
    return 0;
}