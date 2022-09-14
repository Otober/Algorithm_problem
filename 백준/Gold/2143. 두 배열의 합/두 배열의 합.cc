#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t;
int n, m;

long long ans = 0;

vector < int > a;
vector < int > b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    
    cin >> m;
    for(int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        b.push_back(temp);
    }
    
    vector < int > v1;
    for(int i = 0; i < n; i++) {
        int sum = a[i];
        v1.push_back(sum);
        for(int j = i + 1; j < n; j++) {
            sum += a[j];
            v1.push_back(sum);
        }
    }
    
    vector < int > v2;
    for(int i = 0; i < m; i++) {
        int sum = b[i];
        v2.push_back(sum);
        for(int j = i + 1; j < m; j++) {
            sum += b[j];
            v2.push_back(sum);
        }
    }
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), greater < int > ());
    
    int idx1 = 0, idx2 = 0;
    while(idx1 < v1.size() && idx2 < v2.size()) {
        if(v1[idx1] + v2[idx2] == t) {
            long long cnt1 = 1, cnt2 = 1;
            idx1++; idx2++;
            while(idx1 < v1.size() && v1[idx1] == v1[idx1 - 1]) {
                idx1++;
                cnt1++;
            }
            while(idx2 < v2.size() && v2[idx2] == v2[idx2 - 1]) {
                idx2++;
                cnt2++;
            }
            ans += cnt1 * cnt2;
        }
        else if(v1[idx1] + v2[idx2] < t) idx1++;
        else if(v1[idx1] + v2[idx2] > t) idx2++;
    }
    cout << ans;
    return 0;
}