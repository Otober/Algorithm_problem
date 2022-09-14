#include <iostream>
#include <vector>
#define N 100005

using namespace std;

vector < int > adj[N];
bool visit[N] = {};
int parent[N] = {};

void f_circuit(int node) {
    visit[node] = true;
    for(int i = 0; i < adj[node].size(); i++) {
        int next = adj[node][i];
        if(!visit[next]) {
            parent[next] = node;
            f_circuit(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; 
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    f_circuit(1);
    for(int i = 2; i <= n; i++) {
        cout << parent[i] << "\n";
    }
    return 0;
}