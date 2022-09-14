#include <iostream>

using namespace std;

int recursive(int n) {
    if(n == 1) return 1;
    if(n == 0) return 1;
    return n*recursive(n-1);
}

int main() {
    int n;
    cin >> n;
    cout << recursive(n) << endl;
    return 0;
}