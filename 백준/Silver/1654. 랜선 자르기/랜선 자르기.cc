#include <iostream>
#define N 10005

using namespace std;

int n, k;
long long int arr[N] = {};

int binary_search(int wire) {
    long long int start = 1;
    long long int end = wire;
    long long int max_wire = 0;
    
    while(start <= end) {
        long long int mid = (start + end) / 2;
        int cnt = 0;
        for(int i = 0; i < k; i++) {
            cnt += arr[i] / mid;
        }
        if(cnt >= n) {
            if(mid > max_wire) max_wire = mid;
            start = mid + 1;
        }
        else end = mid - 1;
    }
    return max_wire;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long int wire = 0;
    
    cin >> k >> n;
    for(int i = 0; i < k; i++) {
        cin >> arr[i];
        if(wire < arr[i]) wire = arr[i];
    }
    cout << binary_search(wire) << endl;
    return 0;
}