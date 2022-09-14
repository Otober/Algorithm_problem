#include <iostream>
#define N 15

using namespace std;

int n;
int arr[N] = {};
int ans[N] = {};

void f_lotto(int cnt, int temp) {
    if(cnt == 6) {
        for(int i = 0; i < cnt; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i = temp; i < n; i++) {
        ans[cnt] = arr[i];
        f_lotto(cnt + 1, i + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(true) {
        cin >> n;
        if(n == 0) break;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        f_lotto(0, 0);
        cout << "\n";
    }
    return 0;
}