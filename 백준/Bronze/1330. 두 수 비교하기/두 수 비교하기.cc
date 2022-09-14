#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if(n > m) cout << ">" << endl;
    if(n < m) cout << "<" << endl;
    if(n == m) cout <<"==" << endl;
    return 0;
}