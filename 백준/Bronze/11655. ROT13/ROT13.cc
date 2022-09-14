#include <iostream>
#include <string>

using namespace std;

string st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    getline(cin, st);
    for(int i = 0; i < st.size(); i++) {
        if(st[i] >= 'A' && st[i] <= 'Z') {
            if(st[i] + 13 > 'Z') cout << (char)('A' + (st[i] + 13) - 'Z' - 1);
            else cout << (char)(st[i] + 13);
        }
        else if(st[i] >= 'a' && st[i] <= 'z') {
            if(st[i] + 13 > 'z') cout << (char)('a' + (st[i] + 13) - 'z' - 1);
            else cout << (char)(st[i] + 13);
        }
        else cout << st[i];
    }
    return 0;
}