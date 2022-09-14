#include <iostream>
#define N 205

using namespace std;

int parent[N] = {};

int f_find(int node) {
    while(node != parent[node]) node = parent[node];
    return node;
}

void f_union(int x, int y) {
    x = f_find(x);
    y = f_find(y);
    if(x < y) parent[y] = x;
    else parent[x] = y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) parent[i] = i;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int temp;
            cin >> temp;
            if(temp) f_union(i, j);
        }
    }
    for(int i = 0; i < m; i++) {
        int main_parent;
        int temp;
        cin >> temp;
        if(i == 0) {
            main_parent = f_find(temp);
        }
        else {
            if(main_parent != f_find(temp)) {
                cout << "NO";
                break;
            }
            if(i == m - 1) {
                cout << "YES";
                break;
            }
        }
    }
    return 0;
}