#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, a, b;
    long long answer = 0;
    vector < long long > v;
    cin >> n;
    for(int i = 0; i < n; i++) {
        long long temp;
        cin >> temp;
        v.push_back(temp);
    }
    cin >> a >> b;
    for(long long iter : v) {
        iter -= a;
        if(iter < 0) continue;
        iter += b - 1;
        answer += iter / b;
    }
    answer += n;
    cout << answer;
    return 0;
}