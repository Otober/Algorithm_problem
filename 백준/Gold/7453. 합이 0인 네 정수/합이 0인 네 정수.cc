#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

long long ans = 0;

vector < int > a;
vector < int > b;
vector < int > c;
vector < int > d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    d.resize(n);
    
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    
    vector < int > v1;
    vector < int > v2;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int temp1 = a[i] + b[j];
            int temp2 = c[i] + d[j];
            v1.push_back(temp1);
            v2.push_back(temp2);
        }
    }
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), greater < int >());
    
    int idx1 = 0, idx2 = 0;
    while(idx1 < n * n && idx2 < n * n) {
        if(v1[idx1] + v2[idx2] == 0) {
            long long cnt1 = 1, cnt2 = 1;
            idx1++; idx2++;
            while(idx1 < n * n && v1[idx1] == v1[idx1 - 1]) {
                idx1++;
                cnt1++;
            }
            while(idx2 < n * n && v2[idx2] == v2[idx2 - 1]) {
                idx2++;
                cnt2++;
            }
            ans += cnt1 * cnt2;
        }
        else if(v1[idx1] + v2[idx2] < 0) idx1++;
        else if(v1[idx1] + v2[idx2] > 0) idx2++;
    }
    cout << ans;
    return 0;
}