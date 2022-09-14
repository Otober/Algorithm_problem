#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 987654321

using namespace std;

void f_initialize(vector < int > &arr, vector < int > &min_tree, vector < int > &max_tree, int node, int start, int end) {
    if(start == end) {
        max_tree[node] = arr[start];
        min_tree[node] = arr[start];
        return;
    }
    
    int mid = (start + end) / 2;
    f_initialize(arr, min_tree, max_tree, node * 2, start, mid);
    f_initialize(arr, min_tree, max_tree, node * 2 + 1, mid + 1, end);
    
    min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
    max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
}

void f_update(vector < int > &min_tree, vector < int > &max_tree, int node, int start, int end, int index, int val) {
    if(index < start || end < index) return;
    if(start == end) {
        min_tree[node] = val;
        max_tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    f_update(min_tree, max_tree, node * 2, start, mid, index, val);
    f_update(min_tree, max_tree, node * 2 + 1, mid + 1, end, index, val);
    
    min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
    max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
}

pair < int, int > f_find(vector < int > &min_tree, vector < int > &max_tree, int node, int start, int end, int left, int right) {
    if(right < start || end < left) return {INF, 0};
    if(left <= start && end <= right) return {min_tree[node], max_tree[node]};
    
    int mid = (start + end) / 2;
    pair < int, int > l = f_find(min_tree, max_tree, node * 2, start, mid, left, right);
    pair < int, int > r = f_find(min_tree, max_tree, node * 2 + 1, mid + 1, end, left, right);
    return {min(l.first, r.first), max(l.second, r.second)};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        int h = ceil(log2(n));
        int tree_size = 1 << (h + 1);
        
        vector < int > arr(n);
        vector < int > min_tree(tree_size);
        vector < int > max_tree(tree_size);
        
        for(int i = 0; i < n; i++) {
            arr[i] = i;
        }
        
        f_initialize(arr, min_tree, max_tree, 1, 0, n - 1);
        while(k--) {
            int q, a, b;
            cin >> q >> a >> b;
            if(q) {
                pair < int, int > ans = f_find(min_tree, max_tree, 1, 0, n - 1, a, b);
                if(ans.first == a && ans.second == b) cout << "YES" << "\n";
                else cout << "NO" << "\n";
            }
            else {
                pair < int, int > l = f_find(min_tree, max_tree, 1, 0, n - 1, a, a);
                pair < int, int > r = f_find(min_tree, max_tree, 1, 0, n - 1, b, b);
                f_update(min_tree, max_tree, 1, 0, n - 1, a, r.first);
                f_update(min_tree, max_tree, 1, 0, n - 1, b, l.first);
            }
        }
    }
    return 0;
}