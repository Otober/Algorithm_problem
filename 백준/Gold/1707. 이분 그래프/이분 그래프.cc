#include <iostream>
#include <vector>
#include <queue>
#define N 20005

using namespace std;

int arr[N] = {};
queue < int > q;
vector < int > v[N];

void f_initialize(int n) {
    fill_n(arr, n + 1, 0);
    while(!q.empty()) q.pop();
    for(int i = 0; i <= n; i++) v[i].clear();
}

bool f_bfs(int start) {
    arr[start] = 1;
    q.push(start);
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        for(int i = 0; i < v[node].size(); i++) {
            int next = v[node][i];
            
            if(arr[next] == 0) {
                arr[next] = 3 - arr[node];
                q.push(next);
            }
            else {
                if(arr[next] == arr[node]) return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        f_initialize(n);
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        
        for(int i = 1; i <= n; i++) {
            if(arr[i] == 0) {
                if(f_bfs(i) == false) {
                    cout << "NO" << "\n";
                    break;
                }
            }
            if(i == n) cout << "YES" << "\n";
        }
    }
    return 0; 
}