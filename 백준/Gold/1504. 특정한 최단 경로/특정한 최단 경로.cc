#include <iostream>
#include <vector>
#include <queue>
#define N 805
#define INT_MAX 987654321

using namespace std;

int n, e;
int v_1, v_2;
int visit[N] = {};
vector < pair < int, int > > adj[N];
priority_queue < pair < int, int > > pq;

int f_min(int a, int b) {
    if(a == -1 && b == -1) return -1;
    if(a == -1) return b;
    if(b == -1) return a;
    return a < b ? a : b;
}

int Dijkstar(int st, int end) {
    for(int i = 1; i <= n; i++) {
        visit[i] = INT_MAX;
    }
    visit[st] = 0;
    pq.push(make_pair(-visit[st],st));
    while(!pq.empty()) {
        int now = pq.top().second;
        pq.pop();
        
        for(int i = 0; i < adj[now].size(); i++) {
            int next = adj[now][i].first;
            int distance = adj[now][i].second;
            if(visit[next] > distance + visit[now]) {
                visit[next] = distance + visit[now];
                pq.push(make_pair(-visit[next], next));
            }
        }
    }
    if(visit[end] == INT_MAX) return -1;
    else return visit[end];
}

int solution(int v_1, int v_2) {
    int a = Dijkstar(1, v_1);
    int b = Dijkstar(v_1, v_2);
    int c = Dijkstar(v_2, n);
    if(a == -1 || b == -1 || c == -1) return -1;
    else return a + b + c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> e;
    
    for(int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }
    cin >> v_1 >> v_2;
    cout << f_min(solution(v_1, v_2), solution(v_2, v_1));
    return 0;
}
