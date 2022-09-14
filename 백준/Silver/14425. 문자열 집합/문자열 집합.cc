#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    int cnt = 0;
    cin >> n >> m;
    map < string, bool > mp;
    while(n--) {
        string st;
        cin >> st;
        mp[st] = true;
    }
    
    while(m--) {
        string st;
        cin >> st;
        if(mp[st]) cnt++;
    }
    cout << cnt;
    return 0;
}