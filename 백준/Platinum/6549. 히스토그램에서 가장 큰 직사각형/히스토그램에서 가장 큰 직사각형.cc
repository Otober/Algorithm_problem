#include <iostream>
#include <cmath>
#include <vector>
typedef long long ll;

using namespace std;

void f_init(vector < int > &arr, vector < int > &tree, int node, int start, int end) {
    if(start == end) tree[node] = start;
    else {
        int mid = (start + end) / 2;
        f_init(arr, tree, node * 2, start, mid);
        f_init(arr, tree, node * 2 + 1, mid + 1, end);
        if(arr[tree[node * 2]] <= arr[tree[node * 2 + 1]]) tree[node] = tree[node * 2];
        else tree[node] = tree[node * 2 + 1];
    }
}

int f_height(vector < int > &arr, vector < int > &tree, int node, int start, int end, int left, int right) {
    if(left > end || right < start) return -1;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    int left_tree = f_height(arr, tree, node * 2, start, mid, left, right);
    int right_tree = f_height(arr, tree, node * 2 + 1, mid + 1, end, left, right);
    if(left_tree == -1) return right_tree;
    else if(right_tree == -1) return left_tree;
    else return (arr[left_tree] <= arr[right_tree]) ? left_tree : right_tree;
}

ll f_max(vector < int > &arr, vector < int > &tree, int start, int end) {
    int n = arr.size();
    int m = f_height(arr, tree, 1, 0, n - 1, start, end);
    
    ll area = (ll)(end - start + 1) * (ll)arr[m];
    
    if(start <= m - 1) {
        ll temp = f_max(arr, tree, start, m - 1);
        area = (area < temp) ? temp : area;
    }
    if(m + 1 <= end) {
        ll temp = f_max(arr, tree, m + 1, end);
        area = (area < temp) ? temp : area;
    }
    return area;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(true) {
        int n;
        cin >> n;
        if(n == 0) break;
        
        int h = (int)ceil(log2(n)) + 1;
        int tree_size = 1 << h;
        
        vector < int > arr(n);
        vector < int > tree(tree_size);
        
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        f_init(arr, tree, 1, 0, n - 1);
        
        cout << f_max(arr, tree, 0, n - 1) << "\n";
    }
    return 0;
}