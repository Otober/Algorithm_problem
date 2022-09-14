#include <iostream>
#include <vector>
#include <queue>
#define N 32005

using namespace std;

int n, m;
priority_queue < int > pq;
int indegree[N] = {};
vector < int > graph[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        indegree[b]++;
        graph[a].push_back(b);
    }
    
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) pq.push(-i);
    }
    
    while(!pq.empty()) {
        int temp = -pq.top();
        pq.pop();
        
        cout << temp << " ";
        
        for(int i = 0; i < graph[temp].size(); i++) {
            int next = graph[temp][i];
            indegree[next]--;
            if(indegree[next] == 0) pq.push(-next);
        }
    }
    return 0;
}