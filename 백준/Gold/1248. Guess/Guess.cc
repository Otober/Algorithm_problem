#include <iostream>

using namespace std;

const int N = 10;

bool flag = false;

int n;

char arr[N][N] = {};

int ans[N] = {};

bool f_check(int cnt) {
    int sum = 0;
    for(int i = cnt; i >= 0; i--) {
        sum += ans[i];
        if(arr[i][cnt] == '-' && sum >= 0) return false;
        if(arr[i][cnt] == '+' && sum <= 0) return false;
        if(arr[i][cnt] == '0' && sum != 0) return false;
    }
    return true;
}

void f_dfs(int cnt) {
    if(flag) return;
    if(cnt == n) {
        for(int i = 0; i < cnt; i++) {
            cout << ans[i] << " ";
        }
        flag = true;
        return;
    }
    else {
        for(int i = -N; i <= N; i++) {
            ans[cnt] = i;
            if(f_check(cnt)) f_dfs(cnt + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    f_dfs(0);
}