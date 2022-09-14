#include <iostream>
#include <vector>
#include <cmath>
#define devive 1000000007

using namespace std;

typedef long long ll;

ll f_initialize(vector < ll > &arr, vector < ll > &tree, int node, int start, int end) {
    if(start == end) return tree[node] = arr[start];
    
    int mid = (start + end) / 2;
    ll left = f_initialize(arr, tree, node * 2, start, mid) % devive;
    ll right = f_initialize(arr, tree, node * 2 + 1, mid + 1, end) %devive;
    return tree[node] = (left * right) % devive;
}

ll f_update(vector < ll > &tree, int node, int start, int end, int index, ll val) {
    if(index < start || end < index) return tree[node];
    if(start == end) return tree[node] = val;
    
    int mid = (start + end) / 2;
    ll left = f_update(tree, node * 2, start, mid, index, val) % devive;
    ll right = f_update(tree, node * 2 + 1, mid + 1, end, index, val) % devive;
    return tree[node] = (left * right) % devive;
}

ll f_mul(vector < ll > &tree, int node, int start, int end, int left, int right) {
    if(left > end || right < start) return 1;
    if(left <= start && end <= right) return tree[node];
    
    int mid = (start + end) / 2;
    ll l_mul = f_mul(tree, node * 2, start, mid, left, right) % devive;
    ll r_mul = f_mul(tree, node * 2 + 1, mid + 1, end, left, right) % devive;
    return (l_mul * r_mul) % devive;
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
    f_initialize(arr, tree, 1, 0, n - 1);
    
    m += k;
    while(m--) {
        int way;
        cin >> way;
        if(way == 1) {
            int index;
            ll val;
            cin >> index >> val;
            f_update(tree, 1, 0, n - 1, index - 1, val);
        }
        else {
            int left, right;
            cin >> left >> right;
            cout << f_mul(tree, 1, 0, n - 1, left - 1, right - 1) % devive << "\n";
        }
    }
    return 0;
}