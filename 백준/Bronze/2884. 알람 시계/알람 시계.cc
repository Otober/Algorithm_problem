#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if(m - 45 < 0) {
        n--;
        if(n < 0) {
            n = 23;
        }
        m = m + 60 - 45;
    }
    else {
        m -= 45;
    }
    cout << n << " " << m <<endl;
    return 0;
}