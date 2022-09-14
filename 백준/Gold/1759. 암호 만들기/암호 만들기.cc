#include <iostream>
#include <algorithm>
#define N 17

using namespace std;

int l, c;
char arr[N] = {};
char ans[N] = {};

bool f_check(char temp) {
    if(temp == 'a') return true;
    if(temp == 'e') return true;
    if(temp == 'i') return true;
    if(temp == 'o') return true;
    if(temp == 'u') return true;
    return false;
}

void f_dfs(int cnt, int now) {
    if(cnt == l) {
        int consonant = 0;
        int vowel = 0;
        for(int i = 0; i < l; i++) {
            if(f_check(ans[i])) consonant++;
            else vowel++;
        }
        if(consonant >= 1 && vowel >= 2) {
            for(int i = 0; i < l; i++) {
                cout << ans[i];
            }
            cout << "\n";
        }
        return;
    }
    
    for(int i = now; i < c; i++) {
        ans[cnt] = arr[i];
        f_dfs(cnt + 1, i + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> l >> c;
    for(int i = 0; i < c; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + c);
    f_dfs(0, 0);
    return 0;
}