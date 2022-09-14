#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int ans = 0, b;
    string st;
    cin >> st >> b;
    
    int j = 1;
    for(int i = st.size() - 1; i >= 0; i--) {
        if(st[i] >= 'A' && st[i] <= 'Z') ans += (st[i] - 'A' + 10) * j;
        else ans += (st[i] - '0') * j;
        j *= b;
    } 
    cout << ans;
    return 0;
}