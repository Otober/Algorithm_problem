#include <iostream>
#include <vector>
#include <queue>
#define N 100005
#define INF 987654321

using namespace std;

int n;
int visit[N] = {};

vector < pair < int, int > > arr[N];

priority_queue < pair < int, int > > pq;

int f_bfs(int node) {
    fill_n(visit, n + 1, INF);
    visit[node] = 0;
    pq.push(make_pair(-visit[node], node));
    
    while(!pq.empty()) {
        int here = pq.top().second;
        pq.pop();
        
        for(int i = 0; i < arr[here].size(); i++) {
            int next = arr[here][i].first;
            int ncost = arr[here][i].second;
            
            if(visit[next] > visit[here] + ncost) {
                visit[next] = visit[here] + ncost;
                pq.push(make_pair(-visit[next], next));
            }
        }
    }
    
    int temp = 1;
    for(int i = 1; i <= n; i++) {
        if(visit[temp] < visit[i]) temp = i;
    }
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int node;
        cin >> node;
        while(true) {
            int next;
            cin >> next;
            if(next == -1) break;
            int val;
            cin >> val;
            arr[node].push_back(make_pair(next, val));
        }
    }
    
    cout << visit[f_bfs(f_bfs(1))];
    return 0;
}