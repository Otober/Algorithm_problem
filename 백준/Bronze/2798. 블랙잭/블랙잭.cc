#include <iostream>
#define N 105

using namespace std;

int arr[N];

int main() {
    int n, m;
    int sum = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if(arr[i] + arr[j] + arr[k] <= m && arr[i] + arr[j] + arr[k] > sum) {
                    sum = arr[i] + arr[j] + arr[k];
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}