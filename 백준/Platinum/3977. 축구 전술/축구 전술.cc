#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const int N = 100005;

int cnt = 0;
int tcnt = 0;

int scc[N] = {};
int discover[N] = {};
int indegree[N] = {};

stack < int > st;

vector < int > v[N];

void f_initialize() {
    cnt = 0;
    tcnt = 0;
    fill_n(scc, N, -1);
    fill_n(discover, N, -1);
    fill_n(indegree, N, 0);
    while(!st.empty()) st.pop();
    for(int i = 0; i < N; i++) {
        v[i].clear();
    }
}

int f_dfs(int now) {
    discover[now] = cnt++;
    int ret = discover[now];
    st.push(now);
    for(int next : v[now]) {
        if(discover[next] == -1) ret = min(ret, f_dfs(next));
        else if(scc[next] == -1) ret = min(ret, discover[next]);
    }
    
    if(ret == discover[now]) {
        while(true) {
            int t = st.top();
            st.pop();
            scc[t] = tcnt;
            if(t == now) break;
        }
        tcnt++;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        f_initialize();
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
        }
        
        for(int i = 0; i < n; i++) {
            if(discover[i] == -1) f_dfs(i);
        }
        for(int i = 0; i < n; i++) {
            for(int j : v[i]) {
                if(scc[i] != scc[j]) indegree[scc[j]]++;
            }
        }
        int flag = -1;
        for(int i = 0; i < tcnt; i++) {
            if(indegree[i] == 0) {
                if(flag == -1) flag = i;
                else {
                    flag = -1;
                    cout << "Confused" << "\n";
                    break;
                }
            }
        }
        if(flag != -1) {
            for(int i = 0; i < n; i++) {
                if(indegree[scc[i]] == 0) cout << i << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}