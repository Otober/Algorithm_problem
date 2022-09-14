#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define N 1005

using namespace std;

int n, m;
int cnt;
int scctotal;

int sn[2 * N];
int dfsn[2 * N];

bool flag;

bool finished[2 * N];

vector < int > vt[2 * N];

stack < int > st;

void f_initialize() {
    flag = true;
    cnt = 0;
    scctotal = 0;
    fill_n(sn, 2 * N, 0);
    fill_n(dfsn, 2 * N, 0);
    fill_n(finished, 2 * N, false);
    for(int i = 0; i < 2 * N; i++) {
        vt[i].clear();
    }
    while(!st.empty()) st.pop();
}

int f_neg(int x) {
    return (x > n) ? x - n : x + n;
}

int f_dfs(int node) {
    dfsn[node] = ++cnt;
    st.push(node);
    
    int result = dfsn[node];
    for(int next : vt[node]) {
        if(dfsn[next] == 0) result = min(result, f_dfs(next));
        else if(!finished[next]) result = min(result, dfsn[next]);
    }
    
    if(result == dfsn[node]) {
        scctotal++;
        while(true) {
            int t = st.top();
            st.pop();
            sn[t] = scctotal;
            finished[t] = true;
            if(t == node) break;
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(cin >> n >> m) {
        f_initialize();
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            if(a < 0) a = -a + n;
            if(b < 0) b = -b + n;
            if(a == 1 || b == n + 1) b = a;
            if(b == 1 || a == n + 1) a = b;
            vt[f_neg(a)].push_back(b);
            vt[f_neg(b)].push_back(a);
        }
        for(int i = 1; i <= n; i++) {
            if(dfsn[i] == 0) f_dfs(i);
        }
        
        for(int i = 1; i <= n; i++) {
            if(sn[i] == sn[i + n]) flag = false;
        }
        if(flag) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
    return 0;
}