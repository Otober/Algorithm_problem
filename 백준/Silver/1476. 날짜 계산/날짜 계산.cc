#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int e = 1, s = 1, m = 1;
    int ans = 1;
    int E, S, M;
    
    cin >> E >> S >> M;
    while(true) {
        if(e == E && s == S && m == M) {
            cout << ans;
            break;
        }
        e++;
        s++;
        m++;
        ans++;
        if(e > 15) e = 1;
        if(s > 28) s = 1;
        if(m > 19) m = 1;
    }
    return 0;
}