#include <iostream>
#define N 10005

using namespace std;

bool visit[N] = {};
int parent[N] = {};

void f_initialize(int n) {
    for(int i = 1; i <= n; i++) {
        visit[i] = false;
        parent[i] = i;
    }
}

void f1_find(int node) {
    while(true) {
        visit[node] = true;
        if(node == parent[node]) return;
        node = parent[node];
    }
}

void f2_find(int node) {
    while(true) {
        if(visit[node] == true) {
            cout << node << "\n";
            return;
        }
        if(node == parent[node]) return;
        node = parent[node];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        int node1, node2;
        cin >> n;
        f_initialize(n);
        for(int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            parent[b] = a;
        }
        cin >> node1 >> node2;
        f1_find(node1);
        f2_find(node2);
    }
    return 0;
}