#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define N 105

using namespace std;

vector < pair < double, double > > adj;
vector < pair < double, pair < int, int > > > arr;
int parent[N] = {};
double ans = 0;

double f_calculate(pair < double, double > a, pair < double, double > b) {
    return sqrt(pow(a.first - b.first, 2.0) + pow(a.second - b.second, 2.0));
}

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
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;
        adj.push_back(make_pair(a, b));
        parent[i] = i;
    }
    
    for(int i = 0; i < adj.size(); i++) {
        for(int j = i + 1; j < adj.size(); j++) {
            arr.push_back(make_pair(f_calculate(adj[i],adj[j]), make_pair(i ,j)));
        }
    }
    
    sort(arr.begin(), arr.end());
    
    for(int i = 0; i < arr.size(); i++) {
        double distance = arr[i].first;
        int node1 = arr[i].second.first;
        int node2 = arr[i].second.second;
        
        if(f_find(node1) != f_find(node2)) {
            f_union(node1, node2);
            ans += distance;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << ans;
    return 0;
}