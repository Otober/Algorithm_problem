#include <iostream>
#define N 20

using namespace std;

int t[N] = {};
int p[N] = {};
int dy[N] = {};

int f_max(int x, int y) {
    return x > y ? x : y;
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i<= n; i++) {
        cin >> t[i] >> p[i];
    }
    
    for(int i = n; i > 0; i--) {
        if(t[i] + i > n + 1) {
            dy[i] = dy[i + 1];
        }
        else {
            dy[i] = f_max(dy[i + 1], dy[i + t[i]] + p[i]);
        }
    }
    cout << dy[1] << endl;
    return 0;
}