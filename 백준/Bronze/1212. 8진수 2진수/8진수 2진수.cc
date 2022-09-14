#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string st, ans;
    cin >> st;
    if(st == "0") cout << "0";
    else {
        for(int i = st.size() - 1; i >= 0; i--) {
            int temp = st[i] - '0';
            for(int j = 0; j < 3; j++) {
                ans += (temp % 2) + '0';
                temp /= 2;
            }
        }
        reverse(ans.begin(), ans.end());
        bool flag = false;
        for(int i = 0; i < ans.size(); i++) {
            if(ans[i] == '1') flag = true;
            if(flag) cout << ans[i];
        }
    }
    return 0;
}