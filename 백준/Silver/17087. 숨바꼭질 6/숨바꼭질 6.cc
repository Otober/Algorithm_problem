#include <iostream>

using namespace std;

const int N = 100005;

int arr[N] = {};

int f_gcd(int a, int b) {
    return (b == 0) ? a : f_gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, s;
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr[i] = abs(temp - s);
    }
    for(int i = 1; i < n; i++) {
        int temp = f_gcd(arr[i - 1], arr[i]);
        arr[i] = temp;
    }
    cout << arr[n - 1];
    return 0;
}