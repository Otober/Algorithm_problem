#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

ll f_initialize(vector < ll > &arr, vector < ll > &tree, int node, int start, int end) {
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    ll left = f_initialize(arr, tree, node * 2, start, mid);
    ll right = f_initialize(arr, tree, node * 2 + 1, mid + 1, end);
    return tree[node] = left + right;
}

void f_update_lazy(vector < ll > &tree, vector < ll > &lazy, int node, int start, int end) {
    if(lazy[node] == 0) return;
    tree[node] += (end - start + 1) * lazy[node];
    if(start != end) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

void f_update(vector < ll > &tree, vector < ll > &lazy, int node, int start, int end, int left, int right, ll val) {
    f_update_lazy(tree, lazy, node, start, end);
    if(right < start || left > end) return;
    if(left <= start && end <= right) {
        tree[node] += (end - start + 1) * val;
        if(start != end) {
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }
    }
    else {
        int mid = (start + end) / 2;
        f_update(tree, lazy, node * 2, start, mid, left, right, val);
        f_update(tree, lazy, node * 2 + 1, mid + 1, end, left, right, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

ll f_sum(vector < ll > &tree, vector < ll > &lazy, int node, int start, int end, int left, int right) {
    f_update_lazy(tree, lazy, node, start, end);
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    ll l_sum = f_sum(tree, lazy, node * 2, start, mid, left, right);
    ll r_sum = f_sum(tree, lazy, node * 2 + 1, mid + 1, end, left, right);
    return l_sum + r_sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    int h = ceil(log2(n));
    int tree_size = 1 << (h + 1);
    
    vector < ll > arr(n);
    vector < ll > tree(tree_size);
    vector < ll > lazy(tree_size);
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    f_initialize(arr, tree, 1, 0, n - 1);
    
    m += k;
    while(m--) {
        int way;
        cin >> way;
        if(way == 1) {
            int left, right;
            ll val;
            cin >> left >> right >> val;
            f_update(tree, lazy, 1, 0, n - 1, left - 1, right - 1, val);
        }
        else {
            int left, right;
            cin >> left >> right;
            cout << f_sum(tree, lazy, 1, 0, n - 1, left - 1, right - 1) << "\n";
        }
    }
    return 0;
}