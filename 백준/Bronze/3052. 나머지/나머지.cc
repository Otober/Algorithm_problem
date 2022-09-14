#include <iostream>

using namespace std;

int main() {
    bool arr[43] = {};
    int cnt = 0;
    for(int i = 0; i < 10; i++) {
        int temp;
        cin >> temp;
        if(!arr[temp % 42]) {
            cnt++;
            arr[temp % 42] = true;
        }
    }
    cout << cnt;
}
