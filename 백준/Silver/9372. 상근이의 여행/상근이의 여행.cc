#include <iostream>
#define N 1005

using namespace std;

int parent[N] = {};
int n, m, cnt;

int f_find(int node) {
    while(node != parent[node]) node = parent[node];
    return node;
}

void f_union(int x, int y) {
    x = f_find(x);
    y = f_find(y);
    
    if(x == y) return;
    if(x > y) {
        int temp = x;
        x = y;
        y = temp;
    }
    
    parent[y] = x;
    cnt++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        cnt = 0;
        
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            f_union(a, b);
        }
        cout << cnt << "\n";
    }
    return 0;
}