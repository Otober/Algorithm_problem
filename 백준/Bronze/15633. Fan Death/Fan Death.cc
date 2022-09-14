#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    long long sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) sum += i;
    }
    cout << sum * 5 - 24;
    return 0;
}