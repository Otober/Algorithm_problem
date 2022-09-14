#include <iostream> 
#define N 1005

using namespace std;

int dy[N] = {};

int main() {
    int n;
    cin >> n;
    dy[0] = 1;
    dy[1] = 1;
    for(int i = 2 ; i <= n ; i++ ) {
        dy[i] = (dy[i-1] + (2 * dy[i - 2]))%10007;
    }
    cout << dy[n];
    return 0;
}