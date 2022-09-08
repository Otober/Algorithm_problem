#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

const int N = 200005;

typedef long long ll;

stack < int > st;

struct Point {
    ll x, y;
    ll p, q;
    Point(ll _x = 0, ll _y = 0) 
        :x(_x), y(_y), p(1), q(0)
    {}
};

vector < Point > p;
vector < Point > np;

bool cmp(Point &a, Point &b) {
    if(a.q * b.p != a.p * b.q) return a.q * b.p < a.p * b.q;
    else if(a.y != b.y) return a.y < b.y;
    else return a.x < b.x;
}

ll ccw(const Point &a, const Point &b, const Point &c) {
    return (a.x * b.y + b.x * c.y + c.x * a.y) - (a.x * c.y + b.x * a.y + c.x * b.y);
}

ll v_ccw(const Point &a, const Point &b, const Point &c, const Point &d) {
    Point temp = Point(d.x - (c.x - b.x), d.y - (c.y - b.y));
    return -ccw(a, b, temp);
}

ll dist(const Point &a, const Point &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void f_initialize() {
    p.clear();
    np.clear();
    while(!st.empty()) {
        st.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        int next = 2;
        cin >> n;
        f_initialize();
        for(int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            p.push_back(Point(a, b));
        }
        sort(p.begin(), p.end(), cmp);
        for(int i = 1; i < p.size(); i++) {
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
        
        next = 1;
        ll ans = 0;
        int ans1, ans2;
        int size = np.size();
        for(int i = 0; i < size; i++) {
            while((next + 1) != i && v_ccw(np[i], np[i + 1], np[next % size], np[(next + 1) % size]) > 0) {
                if(ans < dist(np[i], np[next % size])) {
                    ans1 = i;
                    ans2 = next % size;
                    ans = dist(np[i], np[next % size]);
                }
                next++;
            }
            if(ans < dist(np[i], np[next % size])) {
                ans1 = i;
                ans2 = next % size;
                ans = dist(np[i], np[next % size]);
            }
        }
        cout << np[ans1].x << " " << np[ans1].y << " " << np[ans2].x << " " << np[ans2].y << "\n";
    }
    return 0;
}