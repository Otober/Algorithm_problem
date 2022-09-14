#include <iostream>
#include <climits>
#define N 100005

using namespace std;

int gas[N] = {};
int road[N] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    int sum = 0, min_cost = INT_MAX;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> road[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> gas[i];
    }
    
    for(int i = 0; i < n - 1; i++) {
        if(min_cost > gas[i]) min_cost = gas[i];
        sum += min_cost * road[i];
    }
    
    cout << sum << endl;
    return 0;
}