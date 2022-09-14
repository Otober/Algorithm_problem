#include <iostream>

using namespace std;

long long int f_pow(int a, int b, int c) {
    if(b == 1) return a;
    else {
        long long int temp = f_pow(a, b / 2, c);
        if(b % 2) return ((temp * temp) % c * a) % c;
        else return (temp * temp) % c;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;
    cin >> a >> b >> c;
    cout << f_pow(a % c, b, c) << endl;
    return 0;
}