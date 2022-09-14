#include <iostream>

using namespace std;

bool f_check(int temp) {
    if(temp == 3) return true;
    if(temp == 6) return true;
    if(temp == 9) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int cnt = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int temp = i;
        while(temp > 0) {
            if(f_check(temp % 10)) cnt++;
            temp /= 10;
        }
    }
    cout << cnt;
    return 0;
}