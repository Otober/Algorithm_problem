#include <iostream>
#include <vector>
#include <cmath>
#define N 100005
#define LOGN 18

using namespace std;

int n, m;
int depth[N] = {};
int arr[N][LOGN] = {};
vector < int > v[N];

void f_tree(int here, int parent) {
    depth[here] = depth[parent] + 1;
    arr[here][0] = parent;
    for(int i = 1; i < LOGN; i++) {
        arr[here][i] = arr[arr[here][i - 1]][i - 1];
    }
    for(int i = 0; i < v[here].size(); i++) {
        int next = v[here][i];
        if(next != parent) f_tree(next, here);
    }
}

void f_swap(int &a, int &b) {
    int temp = b;
    b = a;
    a = temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    depth[0] = -1;
    f_tree(1, 0);
    
    cin >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        if(depth[a] != depth[b]) {
            if(depth[a] > depth[b]) f_swap(a, b);
            for(int i = LOGN - 1; i >= 0; i--) {
                if(depth[a] <= depth[arr[b][i]]) b = arr[b][i];
            }
        }
        int ans = a;
        if(a != b) {
            for(int i = LOGN - 1; i >= 0; i--) {
                if(arr[a][i] != arr[b][i]) {
                    a = arr[a][i];
                    b = arr[b][i];
                }
                ans = arr[a][i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}