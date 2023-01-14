#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 5;

vector < int > v;

int main() {
    int sum = 0;
    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        sum += temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    cout << sum / N << "\n";
    cout << v[2];
    return 0;
}