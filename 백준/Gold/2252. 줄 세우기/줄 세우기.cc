#include <iostream>
#include <queue>
#include <vector>
#define N 32005

using namespace std;

int n, m;
int indegree[N] = {};

vector < int > v[N];

void f_topologySort() {
    int result[N] = {};
    queue < int > q;
    
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) q.push(i);
    }
    
    for(int i = 1; i <= n; i++) {
        int node = q.front();
        q.pop();
        
        result[i] = node;
        for(int i = 0; i < v[node].size(); i++) {
            int next = v[node][i];
            indegree[next]--;
            if(indegree[next] == 0) q.push(next);
        }
    }
    
    for(int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        indegree[b]++;
    }
    f_topologySort();
    return 0;
}