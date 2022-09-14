#include <iostream>

using namespace std;

int count_two(int num) {
    int cnt = 0;
    for(long long int i = 2; num / i > 0 ; i *= 2) {
        cnt += num / i;
    }
    return cnt;
}

int count_five(int num) {
    int cnt = 0;
    for(long long int i = 5; num / i > 0; i *= 5) {
        cnt += num / i;
    }
    return cnt;
}

int f_min(int &a, int &b) {
    return a < b ? a : b;
}

int main() {
    int n, m;
    int two = 0, five = 0;
    cin >> n >> m;
    
    two += count_two(n);
    two -= count_two(m);
    two -= count_two(n - m);
    
    five += count_five(n);
    five -= count_five(m);
    five -= count_five(n - m);
    
    cout << f_min(two, five) << endl;
    return 0;
}