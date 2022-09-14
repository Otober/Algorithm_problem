#include <iostream>

using namespace std;

int f_min(int x, int y) {
    return x < y ? x : y;
}

int main() {
    int a,b,c;
    int sum = 0;
    cin >> a >> b >> c;
    sum += f_min(f_min(a,b),c);
    cin >> a >> b;
    sum += f_min(a,b);
    cout << sum-50 << endl;
    return 0;
}