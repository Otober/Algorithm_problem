#include <iostream>
#include <vector>
#include <cmath>
#define N 2000005

using namespace std;

void f_update(vector < int > &tree, int node, int start, int end, int index, int val) {
    if(index < start || index > end) return;
    if(start == end) {
        tree[node] += val;
        return;
    }
    int mid = (start + end) / 2;
    f_update(tree, node * 2, start, mid, index, val);
    f_update(tree, node * 2 + 1, mid + 1, end, index, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int f_find(vector < int > &tree, int node, int start, int end, int k) {
    if(start == end) return start;
    else {
        int mid = (start + end) / 2;
        if(k <= tree[node * 2]) return f_find(tree, node * 2, start, mid, k);
        else return f_find(tree, node * 2 + 1, mid + 1, end, k - tree[node * 2]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int h = ceil(log2(N));
    int tree_size = 1 << (h + 1);
    
    vector < int > tree(tree_size, 0);
    
    int n;
    cin >> n;
    while(n--) {
        int t, x;
        cin >> t >> x;
        if(t == 1) {
            f_update(tree, 1, 0, N - 1, x, 1);
        }
        else {
            int pos = f_find(tree, 1, 0, N - 1, x);
            f_update(tree, 1, 0, N - 1, pos, -1);
            cout << pos << "\n";
        }
    }
    return 0;
}