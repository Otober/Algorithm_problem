#include <iostream>

using namespace std;

const int N = 1000005;

bool prime[N] = {};

void f_initialize() {
    prime[1] = true;
    for(int i = 2; i <= N / 2; i++) {
        for(int j = 2; i * j < N; j++) {
            prime[i * j] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    f_initialize();
    while(t--) {
        int n;
        int cnt = 0;
        cin >> n;
        for(int i = 1; i <= n / 2; i++) {
            if(prime[i] == false && prime[n - i] == false) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}