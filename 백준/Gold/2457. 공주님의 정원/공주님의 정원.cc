#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int Month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int date(int month, int day) {
    int temp = 0;
    for(int i = 1; i < month; i++) {
        temp += Month[i];
    }
    temp += day;
    return temp;
}

vector < pair < int, int > > v; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v.push_back(make_pair(date(a, b), date(c, d)));
    }
    sort(v.begin(), v.end());
    
    bool flag = false;
    int idx = -1;
    int ans = 0;
    int temp = 0;
    int before = date(3, 1);
    
    while(before <= date(11, 30) && idx < n) {
        flag = false;
        idx++;
        for(int i = idx; i < n; i++) {
            if(v[i].first > before) break;
            if(temp < v[i].second) {
                temp = v[i].second;
                flag = true;
                idx = i;
            }
        }
        if(flag) {
            before = temp;
            ans++;
        }
        else {
            ans = 0;
            break;
        }
    }
    cout << ans;
    return 0;
}