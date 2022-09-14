#include <iostream>
#define N 1000005

using namespace std;

long long int arr[N] = {};

int main() {
    int n;
    cin >> n;
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2; i <= n; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
    }
    cout << arr[n];
    return 0;
}