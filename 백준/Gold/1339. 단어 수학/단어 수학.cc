#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int alphabet[26] = {};

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp = 1;
        string st;
        cin >> st;
        for(int j = st.size() - 1; j >= 0; j--) {
            alphabet[st[j] - 'A'] += temp;
            temp *= 10;
        }
    }
    sort(alphabet, alphabet + 26, cmp);
    
    int ans = 0;
    for(int i = 0; i < 10; i++) {
        ans += alphabet[i] * (9 - i);
    }
    cout << ans;
    return 0;
}