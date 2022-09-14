#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define N 10005

using namespace std;

int v, e;
int cnt = 0;
int scctotal = 0;

int dfsn[N] = {};

bool finished[N] = {};

vector < int > vt[N];
vector < vector < int > > scc;

stack < int > st;

int f_dfs(int here) {
    cnt++;
    dfsn[here] = cnt;
    st.push(here);
    
    int result = dfsn[here];
    for(int next : vt[here]) {
        if(dfsn[next] == 0) result = min(result, f_dfs(next));
        else if(!finished[next]) result = min(result, dfsn[next]);
    }
    
    if(dfsn[here] == result) {
        vector < int > curr_scc;
        while(true) {
            int temp = st.top();
            st.pop();
            
            curr_scc.push_back(temp);
            finished[temp] = true;
            
            if(temp == here) break;
        }
        
        sort(curr_scc.begin(), curr_scc.end());
        scc.push_back(curr_scc);
        scctotal++;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        vt[a].push_back(b);
    }
    
    for(int i = 1; i <= v; i++) {
        if(dfsn[i] == 0) f_dfs(i);
    }
    sort(scc.begin(), scc.end());
    cout << scctotal << "\n";
    for(int i = 0; i < scc.size(); i++) {
        for(int j : scc[i]) {
            cout << j << " ";
        }
        cout << "-1" << "\n";
    }
    return 0; 
}