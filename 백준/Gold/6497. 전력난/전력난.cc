#include <iostream>
#include <vector>
#include <algorithm>
#define N 200005

using namespace std;

int n, m;
int ans = 0;
int sum = 0;
int parent[N] = {};
vector < pair < int, pair < int, int > > > v;

void f_initialize(int n) {
    for(int i = 0; i <= n; i++) parent[i] = i;
    v.clear();
    ans = 0;
    sum = 0;
}

int f_find(int node) {
    while(node != parent[node]) node = parent[node];
    return node;
}

void f_union(int a, int b, int cost) {
    a = f_find(a);
    b = f_find(b);
    if(a == b) return;
    a < b ? parent[b] = a : parent[a] = b;
    ans += cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(true) {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        f_initialize(n);
        for(int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            v.push_back(make_pair(c, make_pair(a, b)));
            sum += c;
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++) {
            int cost = v[i].first;
            int node1 = v[i].second.first;
            int node2 = v[i].second.second;
        
            f_union(node1, node2, cost);
        }
        cout << sum - ans << "\n";
    }
    return 0;
}