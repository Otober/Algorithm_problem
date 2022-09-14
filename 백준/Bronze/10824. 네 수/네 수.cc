#include <iostream>
#include <string>

using namespace std;

string a, b;
string c, d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> a >> b >> c >> d;
    cout << stol(a + b) + stol(c + d);
    return 0;
}