#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define N 100005

using namespace std;

int n, m;
int cnt = 0;
int ans = 0;
int scctotal = 0;

int sn[N] = {};
int dfsn[N] = {};
int inDegree[N] = {};

bool finished[N] = {};

vector < int > v[N];

stack < int > st;

void f_initialize(int n) {
    cnt = 0;
    ans = 0;
    scctotal = 0;
    
    fill_n(sn, n + 1, 0);
    fill_n(dfsn, n + 1, 0);
    fill_n(inDegree, n + 1, 0);
    fill_n(finished, n + 1, 0);
    for(int i = 0; i <= n; i++) {
        v[i].clear();
    }
    while(!st.empty()) st.pop();
}

int f_dfs(int node) {
    dfsn[node] = ++cnt;
    st.push(node);
    
    int result = dfsn[node];
    for(int next : v[node]) {
        if(dfsn[next] == 0) result = min(result, f_dfs(next));
        else if(!finished[next]) result = min(result, dfsn[next]);
    }
    
    if(result == dfsn[node]) {
        while(true) {
            int temp = st.top();
            st.pop();
            finished[temp] = true;
            sn[temp] = scctotal;
            
            if(temp == node) break;
        }
        scctotal++;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        f_initialize(n);
        
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
        }
        for(int i = 1; i <= n; i++) {
            if(dfsn[i] == 0) f_dfs(i);
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j : v[i]) {
                if(sn[i] != sn[j]) inDegree[sn[j]]++;
            }
        }
        
        for(int i = 0; i < scctotal; i++) {
            if(inDegree[i] == 0) ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}