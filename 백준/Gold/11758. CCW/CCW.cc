#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector < pair < int, int > > arr;

long long f_ccw(pair < int, int > &a, pair < int, int > &b, pair < int, int > &c) {
    long long temp = (a.first * b.second) + (a.second * c.first) + (b.first * c.second);
    temp -= (b.second * c.first) + (c.second * a.first) + (a.second * b.first);
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i = 0; i < 3; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back(make_pair(a, b));
    }
    int temp = f_ccw(arr[0], arr[1], arr[2]);
    if(temp < 0) cout << "-1";
    else if(temp > 0) cout << "1";
    else cout << "0";
    return 0;
}