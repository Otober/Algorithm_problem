#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int N = 50005;

int group[N] = {};
int indegree[N] = {};

set < int > s;
set < int > v[N];

queue < int > q;

int f_find(int node) {
    while(group[node] != node) {
        node = group[node];
    }
    return node;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        group[i] = i;
    }
    vector < pair < int, int > > t;
    for(int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> c >> b;
        if(c == '=') {
            a = f_find(a);
            b = f_find(b);
            if(a > b) swap(a, b);
            group[b] = a;
        }
        else {
            t.push_back(make_pair(a, b));
        }
    }
    for(pair < int, int > iter : t) {
        int a = f_find(iter.first);
        int b = f_find(iter.second);
        s.insert(a);
        s.insert(b);
        if(v[b].count(a) == 0) {
            indegree[a]++;
            v[b].insert(a);
        }
    }
    
    int cnt = 0;
    for(int iter : s) {
        if(indegree[iter] == 0) q.push(iter);
    }
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        cnt++;
        for(int next : v[now]) {
            indegree[next]--;
            if(indegree[next] == 0) q.push(next);
        }
    }
    
    if(cnt == s.size()) cout << "consistent" << "\n";
    else cout << "inconsistent" << "\n";
    return 0;
}