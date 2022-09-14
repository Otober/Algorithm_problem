#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n,k;
    int cal_m = 1, cal_k = 1;
    cin >> n >> k;
    for(int i = n - k + 1 ; i <= n; i++) {
        cal_m *= i;
    }
    for(int i = 1; i <= k; i++) {
        cal_k *=i;
    }
    cout << cal_m / cal_k;
    return 0;
}