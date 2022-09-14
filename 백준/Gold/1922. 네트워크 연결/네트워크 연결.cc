#include <iostream>
#include <vector>
#include <algorithm>
#define N 1005

using namespace std;

int n, m;
int ans = 0;
int parent[N] = {};
vector < pair < int, pair < int, int > > > v;

int f_find(int node) {
    while(node != parent[node]) node = parent[node];
    return node;
}

void f_union(int a, int b) {
    a = f_find(a);
    b = f_find(b);
    
    a < b ? parent[b] = a : parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) parent[i] = i;
    
    for(int i = 0; i <= m; i++)  {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(make_pair(c, make_pair(a, b)));
    }
    
    sort(v.begin(), v.end());
    
    for(int i = 0; i < v.size(); i++) {
        int node1 = v[i].second.first;
        int node2 = v[i].second.second;
        int cost = v[i].first;
        
        if(f_find(node1) != f_find(node2)) {
            f_union(node1, node2);
            ans += cost;
        }
    }
    cout << ans << endl;
    return 0;
}