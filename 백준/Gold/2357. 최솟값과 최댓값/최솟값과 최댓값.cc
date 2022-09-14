#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define INF 1000000005

using namespace std;

vector < int > arr;
vector < int > min_tree;
vector < int > max_tree;

void f_init(int node, int start, int end) {
    if(start == end) {
        max_tree[node] = arr[start];
        min_tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    f_init(node * 2, start, mid);
    f_init(node * 2 + 1, mid + 1, end);
    min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
    max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
}

pair < int, int > f_find(int node, int start, int end, int left, int right) {
    if(start > right || end < left) return make_pair(INF, 0);
    if(left <= start && end <= right) return make_pair(min_tree[node], max_tree[node]);
    
    int mid = (start + end) / 2;
    pair < int, int > pair_l = f_find(node * 2, start, mid, left, right);
    pair < int, int > pair_r = f_find(node * 2 + 1, mid + 1, end, left, right);
    return make_pair(min(pair_l.first, pair_r.first), max(pair_l.second, pair_r.second));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    int h = ceil(log2(n));
    int tree_size = 1 << (h + 1);
    
    arr.resize(n);
    min_tree.resize(tree_size);
    max_tree.resize(tree_size);
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    f_init(1, 0, n - 1);
    
    while(m--) {
        int left, right;
        cin >> left >> right;
        pair < int, int > ans = f_find(1, 0, n - 1, left - 1, right - 1);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}