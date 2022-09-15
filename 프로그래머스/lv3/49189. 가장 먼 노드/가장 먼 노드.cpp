#include <string>
#include <vector>
#include <queue>

using namespace std;

const int N = 20005;

int visit[N] = {};

vector < int > v[N];
queue < int > q;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(int i = 0; i < edge.size(); i++) {
        int first = edge[i][0];
        int second = edge[i][1];
        v[first].push_back(second);
        v[second].push_back(first);
    }
    
    for(int i = 1; i <= n; i++) {
        visit[i] = N;
    }
    visit[1] = 0;
    q.push(1);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int i = 0; i < v[node].size(); i++) {
            int next = v[node][i];
            if(visit[next] > visit[node] + 1) {
                visit[next] = visit[node] + 1;
                q.push(next);
            }
        }
    }
    
    int temp = -1;
    for(int i = 2; i <= n; i++) {
        if(temp < visit[i]) {
            temp = visit[i];
            answer = 0;
        }
        if(temp == visit[i]) answer++;
    }
    return answer;
}