#include <iostream>
#include <algorithm>
#define N 10005

using namespace std;

int arr[N] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int idx = n - 1;
    while(idx > 0 && arr[idx - 1] <= arr[idx]) idx--;
    if(idx == 0) cout << "-1";
    else {
        int idx2 = n - 1;
        while(arr[idx - 1] <= arr[idx2]) idx2--;
        swap(arr[idx - 1], arr[idx2]);
        idx2 = n - 1;
        while(idx < idx2) {
            swap(arr[idx], arr[idx2]);
            idx++;
            idx2--;
        }
        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
    }
    return 0;
}