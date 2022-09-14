#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector < pair < long long, long long > > arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        if(a > b) arr.push_back(make_pair(b, a));
    }
    sort(arr.begin(), arr.end());
    
    long long answer = 0;
    if(!arr.empty()) {
        long long right = arr[0].first;
        for(pair < long long, long long > iter : arr) {
            if(right < iter.second) {
                if(right < iter.first) right = iter.first;
                answer += iter.second - right;
                right = iter.second;
            }
        }
        answer *= 2;
    }
    answer += m;
    cout << answer << endl;
    return 0;
}