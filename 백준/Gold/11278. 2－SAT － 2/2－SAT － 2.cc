#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define N 25

using namespace std;

int n, m;
int cnt = 0;
int scctotal = 0;

int sn[2 * N] = {};
int dfsn[2 * N] = {};

bool flag = true;

bool finished[2 * N] = {};

vector < int > vt[2 * N];

stack < int > st;

int f_neg(int index) {
    return (index > n) ? index - n : index + n; 
}

int f_dfs(int node) {
    dfsn[node] = ++cnt;
    st.push(node);
    
    int result = dfsn[node];
    for(int next : vt[node]) {
        if(dfsn[next] == 0) result = min(result, f_dfs(next));
        else if(sn[next] == 0) result = min(result, dfsn[next]);
    }
    
    if(result == dfsn[node]) {
        scctotal++;
        while(true) {
            int t = st.top();
            st.pop();
            finished[t] = true;
            sn[t] = scctotal;
            
            if(t == node) break;
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if(a < 0) a = -a + n;
        if(b < 0) b = -b + n;
        vt[f_neg(a)].push_back(b);
        vt[f_neg(b)].push_back(a);
    }
    
    for(int i = 1; i <= 2 * n; i++) {
        if(dfsn[i] == 0) f_dfs(i);
    }
    
    for(int i = 1; i <= n; i++) {
        if(sn[i] == sn[i + n]) {
            flag = false;
            break;
        }
    }
    if(flag) {
        cout << "1" << "\n";
        for(int i = 1; i <= n; i++) {
            cout << (sn[i] < sn[f_neg(i)]) << " ";
        }
    }
    else cout << "0";
    return 0;
}