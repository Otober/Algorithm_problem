#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 30;

int arr[N] = {};

vector < int > v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b;
    int m;
    cin >> a >> b;
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> arr[i];
    }
    
    int sum = 0;
    int temp = 1;
    for(int i = m - 1; i >= 0; i--) {
        sum += temp * arr[i];
        temp *= a;
    }
    
    while(sum > 0) {
        v.push_back(sum % b);
        sum /= b;
    }
    for(int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << " ";
    }
    return 0;
}