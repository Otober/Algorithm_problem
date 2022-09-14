#include <iostream>
#include <algorithm>
#define N 200005

using namespace std;

int n, c;
int arr[N] = {};

int binary_search() {
    int start = 1;
    int end = arr[n - 1] - arr[0];
    int max_distance = 0;
    while(start <= end) {
        int mid = (start + end) / 2;
        int previous = arr[0];
        int cnt = 1;
        for(int i = 1; i < n; i++) {
            int distance = arr[i] - previous;
            if(mid <= distance) {
                cnt++;
                previous = arr[i];
            }
        }
        if(cnt >= c) {
            max_distance = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return max_distance;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> c;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cout << binary_search() << endl;
}