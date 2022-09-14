#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000005;

int group[N] = {};

int f_group(int node) {
    while(node != group[node]) {
        node = group[node];
    }
    return node;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        group[i] = i;
    }
    
    while(m--) {
        int c, a, b;
        cin >> c >> a >> b;
        
        a = f_group(a);
        b = f_group(b);
        
        if(c == 0) {
            if(b > a) swap(a, b);
            group[b] = a;
        }
        else {
            if(a == b) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
    }
    return 0;
}