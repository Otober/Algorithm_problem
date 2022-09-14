#include <iostream>

using namespace std;

int f_min(int &a, int &b) {
    return a < b ? a : b;
}

int main() {
    int n;
    int two = 0, five = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int temp = i;
        while(temp % 2 == 0 || temp % 5 == 0) {
            if(temp % 2 == 0) {
                two++;
                temp /= 2;
            }
            if(temp % 5 == 0) {
                five++;
                temp /= 5;
            }
        }
    }
    cout << f_min(two, five);
    return 0;
}