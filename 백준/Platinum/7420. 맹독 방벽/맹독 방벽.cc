#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#define _USE_MATH_DEFINES

using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
    ll p, q;
    Point(ll _x, ll _y)
        :x(_x), y(_y), p(1), q(0)
    {}
};

vector < Point > p;
vector < Point > np;

stack < int > st;

double ans = 0;

bool cmp(const Point &a, const Point &b) {
    if(a.q * b.p != a.p * b.q) return a.q * b.p < a.p * b.q;
    else if(a.y != b.y) return a.y < b.y;
    else return a.x < b.x;
}

ll ccw(const Point &a, const Point &b, const Point &c) {
    return (a.x * b.y + b.x * c.y + c.x * a.y) - (a.x * c.y + b.x * a.y + c.x * b.y);
}

double dist(const Point &a, const Point &b) {
    return sqrt(pow(a.x - b.x, 2.0) + pow(a.y - b.y, 2.0));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l;
    int next = 2;
    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        p.push_back(Point(a, b));
    }
    sort(p.begin(), p.end(), cmp);
    for(int i = 1; i < n; i++) {
        p[i].p = p[i].x - p[0].x;
        p[i].q = p[i].y - p[0].y;
    }
    sort(p.begin() + 1, p.end(), cmp);
    st.push(0);
    st.push(1);
    
    while(next < n) {
        while(st.size() >= 2) {
            int first, second;
            second = st.top();
            st.pop();
            first = st.top();
            if(ccw(p[first], p[second], p[next]) > 0) {
                st.push(second);
                break;
            }
        }
        st.push(next++);
    }
    while(!st.empty()) {
        np.push_back(p[st.top()]);
        st.pop();
    }
    for(int i = 0; i < np.size() - 1; i++) {
        ans += dist(np[i], np[i + 1]);
    }
    ans += dist(np[np.size() - 1], np[0]);
    ans += 2 * l * M_PI;
    cout << (ll)(ans + 0.5);
    return 0;
}