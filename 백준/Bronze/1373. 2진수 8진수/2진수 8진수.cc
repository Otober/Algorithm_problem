#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string st, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> st;
    reverse(st.begin(), st.end());
    while(st.size() % 3 != 0) {
        st += '0';
    }
    
    int j = 0;
    for(int i = 0; i < st.size(); i++) {
        if(i % 3 == 2) {
            int sum = 0;
            int temp = 1;
            
            for(int k = j; k <= i; k++) {
                sum += temp * (st[k] - '0');
                temp *= 2;
            }
            j = i + 1;
            ans += (char)(sum + '0');
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}