#include <iostream>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    cout << n * ((m / 1)% 10) << endl;
    cout << n * ((m / 10) % 10) << endl;
    cout << n * ((m / 100) % 10) << endl;
    cout << n * m <<endl;
    return 0;
}