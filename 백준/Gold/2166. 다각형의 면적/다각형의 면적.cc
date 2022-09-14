#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector < pair < long long, long long > > arr;

long long f_ccw(pair < long long, long long > &a, pair < long long, long long > &b, pair < long long, long long > &c) {
    long long temp = (a.first * b.second) + (a.second * c.first) + (b.first * c.second);
    temp -= (b.second * c.first) + (c.second * a.first) + (a.second * b.first);
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    long long sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        arr.push_back(make_pair(a, b));
    }
    for(int i = 1; i < n - 1; i++) {
        sum += f_ccw(arr[0], arr[i], arr[i + 1]);
    }
    if(sum % 2) cout << abs(sum / 2) << ".5" << endl;
    else cout << abs(sum / 2) << ".0" << endl;
    return 0;
}