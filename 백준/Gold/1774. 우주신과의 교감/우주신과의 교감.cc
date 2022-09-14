#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define N 1005

using namespace std;

int n, m;
int parent[N] = {};
double ans;
vector < pair < int, int > > arr;
vector < pair < double, pair < int, int > > > adj;

double get_distance(pair < int, int > a, pair < int, int > b) {
    int test1 = pow(a.first - b.first, 2.0);
    int test2 = pow(a.second - b.second, 2.0);
    double test3 = sqrt(pow(a.first - b.first, 2.0) + pow(a.second - b.second, 2.0));
    return sqrt(pow(a.first - b.first, 2.0) + pow(a.second - b.second, 2.0));
}

int f_find(int node) {
    while(node != parent[node]) node = parent[node];
    return node;
}

bool f_union(int a, int b) {
    a = f_find(a);
    b = f_find(b);
    if(a == b) return false;
    (a < b) ? parent[b] = a : parent[a] = b;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back(make_pair(a, b));
        parent[i] = i;
    }
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        f_union(a, b);
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j ++) {
            adj.push_back(make_pair(get_distance(arr[i], arr[j]), make_pair(i + 1, j + 1)));
        }
    }
    
    sort(adj.begin(), adj.end());
    
    for(int i = 0; i < adj.size(); i++) {
        double distance = adj[i].first;
        int node1 = adj[i].second.first;
        int node2 = adj[i].second.second;
        
        if(f_union(node1, node2)) {
            ans += distance;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << ans;
    return 0;
}