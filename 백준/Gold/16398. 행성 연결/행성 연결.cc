#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1005;

int n;

int parent[N] = {};

vector < pair < int, pair < int, int > > > v;

int f_find_parent(int node) {
    if(node == parent[node]) return node;
    else return parent[node] = f_find_parent(parent[node]);
}

void f_union_parent(int a, int b) {
    a = f_find_parent(a);
    b = f_find_parent(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    long long answer = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        parent[i] = i;
        for(int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            if(i < j) v.push_back(make_pair(temp, make_pair(i, j)));
        }
    }
    sort(v.begin(), v.end());
    
    for(int i = 0; i < v.size(); i++) {
        int a = v[i].second.first;
        int b = v[i].second.second;
        int weight = v[i].first;
        if(f_find_parent(a) != f_find_parent(b)) {
            answer += weight;
            f_union_parent(a, b);
        }
    }
    cout << answer;
    return 0;
}