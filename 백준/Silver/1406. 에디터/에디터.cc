#include <iostream>
#include <string>
#include <list>

using namespace std;

int n;
string str;
list<char> l;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> str;
    cin >> n;
    for(int i = 0; i < str.size(); i++) {
        l.push_back(str[i]);
    }
    
    list<char> :: iterator iter = l.end();
    while(n--) {
        char temp;
        cin >> temp;
        if(temp == 'L') {
            if(iter != l.begin()) iter--;
        }
        else if(temp == 'D') {
            if(iter != l.end()) iter++;
        }
        else if(temp == 'B') {
            if(iter != l.begin()) {
                iter = l.erase(--iter);
            }
        }
        else {
            cin >> temp;
            l.insert(iter, temp);
        }
    }
    for(iter = l.begin(); iter != l.end(); iter++) cout << *iter;
    return 0;
}