#include <iostream>
#include <queue>
#include <stack>

using namespace std;

const int N = 100001;
const int INF = 987654321;

const int d[2] = {-1, 1};

int n, k;

bool visit[N] = {};

int parent[N] = {};

stack < int > st;

queue < pair < int, int > > q;

bool f_check(int now, int next) {
    if(next < 0) return false;
    if(next >= N) return false;
    return true;
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < N; i++) {
        parent[i] = -1;
    }
    
    visit[n] = true;
    parent[n] = -1;
    q.push(make_pair(-0, n));
    
    while(!q.empty()) {
        int cost = -q.front().first;
        int now = q.front().second;
        q.pop();
        
        if(now == k) {
            cout << cost << "\n";
            break;
        }
        
        for(int k = 0; k < 3; k++) {
            int next;
            if(k == 2) next = now + now;
            else next = now + d[k];
            
            if(f_check(now, next)) {
                if(!visit[next]) {
                    visit[next] = true;
                    q.push(make_pair(-(cost + 1), next));
                    parent[next] = now;
                }
            }
        }
    }
    
    while(!q.empty()) {
        q.pop();
    }
    
    int node = k;
    while(node != -1) {
        st.push(node);
        node = parent[node];
    }
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}