#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        string st;
        cin >> st;
        if(st == "1") cout << "E\n";
        else cout << "O\n";
    }
    return 0;
}