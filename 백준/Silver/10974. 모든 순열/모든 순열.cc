#include <iostream>
#define N 10

using namespace std;

int n;
int arr[N] = {};
bool check[N] = {};

void f_permutation(int cnt) {
    if(cnt == n) {
        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i = 1; i <= n; i++) {
        if(check[i] == false) {
            check[i] = true;
            arr[cnt] = i;
            f_permutation(cnt + 1);
            check[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    f_permutation(0);
    return 0;
}