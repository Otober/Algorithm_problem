#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#define INF 987654321

using namespace std;

vector < pair < int, int > > v;
map < pair < int, int >, int > m;

int f_dist(pair < int, int > a, pair < int, int > b) {
    return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}

int f_min(int a, int b) {
    return a < b ? a : b;
}

bool cmp(pair < int, int > &a, pair < int, int > &b) {
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(b, a));
    }
    sort(v.begin(), v.end(), cmp);
    
    m.insert(make_pair(v[0], 1));
    m.insert(make_pair(v[1], 1));
    
    int ans = f_dist(v[0], v[1]);
    int last = 0;
    
    for(int i = 2; i < n; i++) {
        while(last < i) {
            int diff = v[i].second - v[last].second;
            if(diff * diff > ans) {
                m.erase(v[last]);
                last++;
            }
            else break;
        }
        int limit = sqrt(ans);
        
        map < pair < int, int >, int > :: iterator low = m.lower_bound({v[i].first - limit, -INF});
        map < pair < int, int >, int > :: iterator high = m.lower_bound({v[i].first + limit, INF});
    
        for(map < pair < int, int >, int > :: iterator iter = low; iter != high; iter++) {
            ans = f_min(ans, f_dist(iter -> first, v[i]));
        }
        m.insert(make_pair(v[i], 1));
    }
    cout << ans;
    return 0;
}