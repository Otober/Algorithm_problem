#include <iostream>
#include <algorithm>
#define Edge 100005
#define Node 10005

using namespace std;

struct graph {
    int s, e, w;
    bool operator()(graph i, graph j) {
        if(i.w < j. w) return true;
        else return false;
    }
}arr[Edge];

int parent[Node] = {};
int ans = 0;

int f_find(int node) {
    while(node != parent[node]) node = parent[node];
    return node;
}

void f_union(int x, int y, int weight) {
    x = f_find(x);
    y = f_find(y);
    if(x == y) return;
    (x < y) ? parent[y] = x : parent[x] = y;
    ans += weight;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int v, e;
    cin >> v >> e;
    
    for(int i = 1; i <= v; i++) parent[i] = i;
    for(int i = 1; i <= e; i++) cin >> arr[i].s >> arr[i].e >> arr[i].w;
    
    sort(arr + 1, arr + 1 + e, graph());
    for(int i = 1; i <= e; i++) {
        f_union(arr[i].s, arr[i].e, arr[i].w);
    }
    cout << ans;
    return 0;
}