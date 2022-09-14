#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const int N = 10005;

int n, k;
int cnt = 0;
int tcnt = 0;

int sn[N] = {};
int dfsn[N] = {};

stack < int > st;

vector < int > v[N];

int f_neg(int index) {
    return (index > n) ? index - n : index + n;
}

int f_dfs(int now) {
    dfsn[now] = cnt++;
    int ret = dfsn[now];
    st.push(now);
    
    for(int next : v[now]) {
        if(dfsn[next] == -1) ret = min(ret, f_dfs(next));
        else if(sn[next] == -1) ret = min(ret, dfsn[next]);
    }
    
    if(ret == dfsn[now]) {
        while(true) {
            int t = st.top();
            st.pop();
            sn[t] = tcnt;
            if(t == now) break; 
        }
        tcnt++;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    fill_n(sn, N, -1);
    fill_n(dfsn, N, -1);
    for(int i = 0; i < k; i++) {
        int a[4] = {};
        char b[4] = {};
        
        for(int j = 0; j < 3; j++) {
            cin >> a[j] >> b[j];
        }
        a[3] = a[0];
        b[3] = b[0];
        for(int j = 0; j < 4; j++) {
            if(b[j] == 'B') a[j] += n;
        }
        for(int j = 0; j < 3; j++) {
            v[f_neg(a[j])].push_back(a[j + 1]);
            v[f_neg(a[j + 1])].push_back(a[j]);
        }
    }
    for(int i = 1; i <= 2 * n; i++) {
        if(dfsn[i] == -1) f_dfs(i);
    }
    
    bool flag = true;
    for(int i = 1; i <= n; i++) {
        if(sn[i] == sn[i + n]) flag = false;
    }
    if(flag) {
        for(int i = 1; i <= n; i++) {
            if(sn[i] < sn[i + n]) cout << "R";
            else cout << "B";
        }
    }
    else cout << "-1";
    return 0;
}