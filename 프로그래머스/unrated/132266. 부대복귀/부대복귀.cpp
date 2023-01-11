#include <string>
#include <vector>
#include <queue>

using namespace std;

const int N = 100005;
const int INF = 987654321;

int visit[N] = {};

vector < int > v[N] = {};

queue < pair < int, int > > q;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    for(int i = 0; i <= n; i++) {
        visit[i] = INF;
    }
    
    for(int i = 0; i < roads.size(); i++) {
        v[roads[i][0]].push_back(roads[i][1]);
        v[roads[i][1]].push_back(roads[i][0]);
    }

    
    visit[destination] = 0;
    q.push(make_pair(-visit[destination], destination));
    
    while(!q.empty()) {
        int now = q.front().second;
        q.pop();
        
        for(int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];
            if(visit[now] + 1 < visit[next]) {
                visit[next] = visit[now] + 1;
                q.push(make_pair(-visit[next], next));
            }
        }
    }
    for(int i = 0; i < sources.size(); i++) {
        if(visit[sources[i]] == INF) answer.push_back(-1);
        else answer.push_back(visit[sources[i]]);
    }
    return answer;
}