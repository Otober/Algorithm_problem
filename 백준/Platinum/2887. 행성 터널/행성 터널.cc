#include <iostream>
#include <vector>
#include <algorithm>
#define N 100005

using namespace std;

struct Planet {
    int x, y, z;
    int n;
}planet[N];

int n;
int ans = 0;
int parent[N] = {};
vector < pair < int, pair < int, int > > > v;

bool cmpx(Planet &a, Planet &b) {
    return a.x < b.x;
}

bool cmpy(Planet &a, Planet &b) {
    return a.y < b.y;
}

bool cmpz(Planet &a, Planet &b) {
    return a.z < b.z;
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
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> planet[i].x >> planet[i].y >> planet[i].z;
        planet[i].n = i;
        parent[i] = i;
    }
    
    sort(planet + 1, planet + 1 + n, cmpx);
    for(int i = 1; i < n; i++) {
        v.push_back(make_pair(planet[i + 1].x - planet[i].x, make_pair(planet[i].n, planet[i + 1].n)));
    }
    sort(planet + 1, planet + 1 + n, cmpy);
    for(int i = 1; i < n; i++) {
        v.push_back(make_pair(planet[i + 1].y - planet[i].y, make_pair(planet[i].n, planet[i + 1].n)));
    }
    sort(planet + 1, planet + 1 + n, cmpz);
    for(int i = 1; i < n; i++) {
        v.push_back(make_pair(planet[i + 1].z - planet[i].z, make_pair(planet[i].n, planet[i + 1].n)));
    }
    
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        int cost = v[i].first;
        int node1 = v[i].second.first;
        int node2 = v[i].second.second;
        
        f_union(node1, node2, cost);
    }
    cout << ans << endl;
    return 0;
}