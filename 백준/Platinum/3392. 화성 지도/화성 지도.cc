#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 30000;

struct Point {
    int x, y1, y2;
    bool left;
    Point(int _x, int _y1, int _y2, int _left)
        :x(_x), y1(_y1), y2(_y2), left(_left)
    {}
    bool operator < (const Point &res) const {
        return x < res.x;
    }
};

int cnt[4 * N];
int tree[4 * N];

void f_update_tree(int node, int left, int right, int start, int end, int value) {
    if(left > end || right < start) return;
    
    if(left <= start && end <= right) cnt[node] += value;
    else {
        int mid = (start + end) / 2;
        f_update_tree(node * 2, left, right, start, mid, value);
        f_update_tree(node * 2 + 1, left, right, mid + 1, end, value);
    }
    
    if(!cnt[node]) {
        if(start == end) tree[node] = 0;
        else tree[node] = tree[node  * 2] + tree[node * 2 + 1];
    }
    else tree[node] = end - start + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    vector < Point > v;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        v.push_back(Point(x1, y1, y2, true));
        v.push_back(Point(x2, y1, y2, false));
    }
    sort(v.begin(), v.end());
    
    int ans = 0;
    for(int i = 0; i < v.size(); i++) {
        if(i) ans += (v[i].x - v[i - 1].x) * tree[1];
        int value = (v[i].left) ? 1 : -1;
        f_update_tree(1, v[i].y1, v[i].y2 - 1, 0, N - 1, value);
    }
    cout << ans;
    return 0;
}