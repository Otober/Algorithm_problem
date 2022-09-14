#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int N = 500005;

bool restaurant[N] = {};
bool new_restaurant[N] = {};

int cnt = 0;
int tcnt = 0;

int sn[N] = {};
int arr[N] = {};
int dfsn[N] = {};
int new_arr[N] = {};
int new_visit[N] = {};

stack < int > st;

queue < int > q;

vector < int > v[N];
vector < int > new_v[N];
vector < vector < int > > scc; 

void f_initialize() {
    fill_n(sn, N, -1);
    fill_n(dfsn, N, -1);
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
        vector < int > temp;
        while(true) {
            int t = st.top();
            st.pop();
            sn[t] = tcnt;
            temp.push_back(t);
            if(t == now) break;
        }
        tcnt++;
        scc.push_back(temp);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    int s, p;
    cin >> n >> m;
    f_initialize();
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    cin >> s >> p;
    for(int i = 0; i < p; i++) {
        int a;
        cin >> a;
        restaurant[a] = true;
    }
    
    for(int i = 1; i <= n; i++) {
        if(dfsn[i] == -1) f_dfs(i);
    }
    
    s = sn[s];
    for(int i = 0; i < scc.size(); i++) {
        int sum = 0;
        bool flag = false;
        for(int j = 0; j < scc[i].size(); j++) {
            int now = scc[i][j];
            sum += arr[now];
            if(restaurant[now] == true) flag = true;
            for(int next : v[now]) {
                if(sn[now] != sn[next]) new_v[sn[now]].push_back(sn[next]);
            }
        }
        new_arr[i] = sum;
        new_restaurant[i] = flag;
    }
    
    new_visit[s] = new_arr[s];
    q.push(s);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int next : new_v[now]) {
            if(new_visit[next] < new_visit[now] + new_arr[next]) {
                new_visit[next] = new_visit[now] + new_arr[next];
                q.push(next);
            }
        }
    }
    int answer = 0;
    for(int i = 0; i < tcnt; i++) {
        if(new_restaurant[i] == true) {
            answer = max(answer, new_visit[i]);
        }
    }
    cout << answer;
    return 0;
}