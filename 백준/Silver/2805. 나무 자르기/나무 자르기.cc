#include <iostream>
#include <climits>
#define N 1000005

using namespace std;

long long int arr[N] = {};
int n, m;

int binary_search(long long int high_tree) {
    long long int start = 0;
    long long int end = high_tree;
    long long int max_heigh = 0;
    long long int min_sum = INT_MAX;
    while(start <= end) {
        long long int mid = (start + end) / 2;
        long long int sum = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] > mid) sum += arr[i] - mid;
        }
        if(sum >= m) {
            if(min_sum > sum) {
                min_sum = sum;
                max_heigh = mid;
            }
            start = mid + 1;
        }
        else end = mid - 1;
    }
    return max_heigh;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long int high_tree = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(high_tree < arr[i]) high_tree = arr[i];
    }
    
    cout << binary_search(high_tree);
    return 0;
}