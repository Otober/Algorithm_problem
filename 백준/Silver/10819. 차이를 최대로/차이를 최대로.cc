#include <iostream>
#include <cmath>
#define N 10

using namespace std;

int n;
int ans = 0;
int arr[N] = {};
int choice[N] = {};
bool visit[N] = {};

int f_max(int &a, int &b) {
    return a > b ? a : b;
}

void f_permutation(int cnt) {
    if(cnt == n) {
        int temp = 0;
        for(int i = 0; i < n - 1; i++) {
            temp += abs(choice[i] - choice[i + 1]);
        }
        ans = f_max(ans, temp);
        return;
    }
    
    for(int i = 0; i < n; i++) {
        if(visit[i] == false) {
            visit[i] = true;
            choice[cnt] = arr[i];
            f_permutation(cnt + 1);
            visit[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    f_permutation(0);
    cout << ans;
    return 0;
}