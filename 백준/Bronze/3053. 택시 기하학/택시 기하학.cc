#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES

using namespace std;

int main() {
    int r;
    cout << fixed;
    cout.precision(6);
    cin >> r;
    cout << r * r * M_PI << endl;
    cout << r * r * 2.0 << endl;
    return 0;
}