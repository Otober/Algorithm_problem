#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

const int N = 100005;

stack < int > st;

struct Point{
    int x, y;
    int p, q;
    Point(int _x = 0, int _y = 0)
        :x(_x), y(_y), p(1), q(0)
    {}
}p[N];

bool cmp(Point &a, Point &b) {
    if(1LL * a.q * b.p != 1LL * a.p * b.q) return 1LL * a.q * b.p < 1LL * a.p * b.q;
    else if(a.y != b.y) return a.y < b.y;
    else return a.x < b.x;
}

long long ccw(const Point &a, const Point &b, const Point &c) {
    return 1LL * ((a.x * b.y + b.x * c.y + c.x * a.y) - (a.x * c.y + b.x * a.y + c.x * b.y));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int next = 2;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        p[i] = Point(a, b);
    }
    sort(p, p + n, cmp);
    for(int i = 1; i < n; i++) {
        p[i].p = p[i].x - p[0].x;
        p[i].q = p[i].y - p[0].y;
    }
    sort(p + 1, p + n, cmp);
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
    cout << st.size();
    return 0;
}