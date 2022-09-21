#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

const int N = 105;

vector < int > v[N];

int f_bfs(int node, int first, int second) {
    bool visit[N] = {};
    int cnt = 0;
    queue < int > q;
    
    visit[node] = true;
    q.push(node);
    cnt++;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        
        for(int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];
            if(now == first && next == second) continue;
            if(now == second && next == first) continue;
            if(visit[next] == false) {
                visit[next] = true;
                q.push(next);
                cnt++;
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    for(int i = 0; i < wires.size(); i++) {
        v[wires[i][0]].push_back(wires[i][1]);
        v[wires[i][1]].push_back(wires[i][0]);
    }
    for(int i = 0; i < wires.size(); i++) {
        int first = wires[i][0];
        int second = wires[i][1];
        
        int tcnt = abs(f_bfs(first, first, second) - f_bfs(second, first, second));
        if(answer > tcnt) answer = tcnt;
    }
    return answer;
}