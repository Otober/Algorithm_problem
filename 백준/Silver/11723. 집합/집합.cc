#include <iostream>
#include <cstring>
#define N 20

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    unsigned int bitmask = 0;
    int m;
    cin >> m;
    while(m--) {
        string str;
        int temp;
        cin >> str;
        if(str.compare("add") == 0) {
            cin >> temp;
            bitmask = bitmask | (1 << temp);
        }
        else if(str.compare("remove") == 0) {
            cin >> temp;
            bitmask = bitmask & ~(1 << temp);
        }
        else if(str.compare("check") == 0) {
            cin >> temp;
            if(bitmask & (1 << temp)) cout << "1" << "\n";
            else cout << "0" << "\n";
        }
        else if(str.compare("toggle") == 0) {
            cin >> temp;
            bitmask = bitmask ^ (1 << temp);
        }
        else if(str.compare("all") == 0) {
            bitmask = bitmask | ((1 << (N + 1)) - 1);
        }
        else if(str.compare("empty") == 0) {
            bitmask = 0;
        }
    }
    return 0;
}