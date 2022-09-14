#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

ll f_init(vector < ll > &tree, vector < ll > &arr, int node, int start, int end) {
    if(start == end) return tree[node] = arr[start];
    
    int mid = (start + end) / 2;
    ll left = f_init(tree, arr, node * 2, start, mid);
    ll right = f_init(tree, arr, node * 2 + 1, mid + 1, end);
    return tree[node] = left + right;
}

void f_update(vector < ll > &tree, int node, int start, int end, int index, ll diff) {
    if(start > index || end < index) return;
    
    tree[node] += diff;
    
    if(start != end) {
        int mid = (start + end) / 2;
        f_update(tree, node * 2, start, mid, index, diff);
        f_update(tree, node * 2 + 1, mid + 1, end, index, diff);
    }
}

ll f_sum(vector < ll > &tree, int node, int start, int end, int left, int right) {
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    
    int mid = (start + end) / 2;
    ll sum_l = f_sum(tree, node * 2, start, mid, left, right);
    ll sum_r = f_sum(tree, node * 2 + 1, mid + 1, end, left, right);
    return sum_l + sum_r;
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
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    f_init(tree, arr, 1, 0, n - 1);
    
    m += k;
    while(m--) {
        int way;
        cin >> way;
        if(way == 1) {
            int pos;
            ll val;
            cin >> pos >> val;
            ll diff = val - arr[pos - 1];
            arr[pos - 1] = val;
            f_update(tree, 1, 0, n - 1, pos - 1, diff);
        }
        else if(way == 2) {
            int left, right;
            cin >> left >> right;
            cout << f_sum(tree, 1, 0, n - 1, left - 1, right - 1) << "\n";
        }
    }
    return 0;
}