#include <iostream>
#define N 4000005

using namespace std;

const long long int  p = 1000000007;
long int fac[N];
long int x_after, x_before, temp, q;

void euclidean(long int p, long int tmp) {
    if(p % tmp > 0) {
        euclidean(tmp, p % tmp);
        temp = x_after;
        x_after = x_before - (p / tmp) * x_after;
        x_before = temp;
    }
    else {
        x_after = 1;
        x_before = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    
    fac[0] = fac[1] = 1;
    for(int i = 2; i <=n; i++) {
        fac[i] = (fac[i - 1] * i) % p;
    }
    
    long int tmp = (fac[k] * fac[n - k]) % p;
    euclidean(p, tmp);
    long int result = ((fac[n] % p) * (x_after % p)) % p;
    if(result < 0) result += p;
    cout << result << endl;
    return 0;
}