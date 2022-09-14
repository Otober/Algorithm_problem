#include <iostream>
#define N 105

using namespace std;

int arr[N] = {};
int divisor[N] = {};

int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 1; i < n; i++) {
        int temp = gcd(arr[0], arr[i]);
        cout << arr[0] / temp << "/" << arr[i] / temp << "\n";
    }
    
    return 0;
}