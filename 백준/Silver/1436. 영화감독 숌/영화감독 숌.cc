#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    int cnt = 0;
    int temp = 665;
    cin >> n;
    while(temp++) {
        string str = to_string(temp);
        if(str.find("666") != -1) {
            cnt ++;
        }
        if(cnt == n) {
                cout << temp << endl;
                break;
            }
    }
    return 0;
}