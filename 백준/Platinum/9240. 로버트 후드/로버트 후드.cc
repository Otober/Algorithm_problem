#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define N 100005

using namespace std;

typedef long long ll;

vector < int > vt;

struct Point {
    int x, y;
    int p, q;
    
    Point(int _x = 0, int _y = 0)
        :x(_x), y(_y), p(1), q(0)
    {}
}p[N];

bool cmp(const Point &a, const Point &b) {
    if(1LL * a.q * b.p != 1LL * a.p * b.q) {
        return 1LL * a.q * b.p < 1LL * a.p * b.q;
    }
    if(a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

ll ccw(const Point &a, const Point &b, const Point &c) {
    return 1LL * ((a.x * b.y + b.x * c.y + c.x * a.y) - (a.x * c.y + b.x * a.y + c.x * b.y));
}

double f_dist(const Point &a, const Point &b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int next = 2;
    double ans = -1.0;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p[i] = Point(x, y);
    }
    sort(p, p + n, cmp);
    
    for(int i = 1; i < n; i++) {
        p[i].p = p[i].x - p[0].x;
        p[i].q = p[i].y - p[0].y;
    }
    
    sort(p + 1, p + n, cmp);
    
    vt.push_back(0);
    vt.push_back(1);
    
    while(next < n) {
        while(vt.size() >= 2) {
            int first, second;
            second = vt.back();
            vt.pop_back();
            first = vt.back();
            if(ccw(p[first], p[second], p[next]) > 0) {
                vt.push_back(second);
                break;
            }
        }
        vt.push_back(next++);
    }
    
    for(int i = 0; i < vt.size(); i++) {
        for(int j = i + 1; j < vt.size(); j++) {
            ans = max(ans, f_dist(p[vt[i]], p[vt[j]]));
        }
    }
    cout << fixed;
    cout.precision(8);
    cout << ans;
    return 0;
}