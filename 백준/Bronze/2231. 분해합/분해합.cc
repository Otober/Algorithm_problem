#include <iostream>

using namespace std;

int main() {
    int n;
    bool flag = false;
    cin >> n;
    for(int i = 0; i <= n; i++) {
        int temp = i;
        int sum = temp;
        while(temp) {
            sum += temp % 10;
            temp /= 10;
        }
        if(sum == n) {
            cout << i << endl;
            flag = true;
            break;
        }
    }
    if(flag == false) {
        cout << "0" << endl;
    }
    return 0;
}