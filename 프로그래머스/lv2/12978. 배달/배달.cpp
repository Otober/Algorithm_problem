#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int M = 55;
const int INT_MAX = 987654321;

int visit[M] = {};

priority_queue < pair < int, int > > pq;

vector < pair < int, int >  > v[M];

void f_initialize() {
    for(int i = 0; i < M; i++) {
        visit[i] = INT_MAX;
    }
}

bool f_check(int now, int next, int cost, int K) {
    if(visit[now] + cost >= visit[next]) return false;
    if(visit[now] + cost > K) return false;
    return true;
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    f_initialize();
    for(int i = 0; i < road.size(); i++) {
        v[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
        v[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    }
    visit[1] = 0;
    pq.push(make_pair(-visit[1], 1));
    while(!pq.empty()) {
        int now = pq.top().second;
        pq.pop();
        
        for(int i = 0; i < v[now].size(); i++) {
            int next = v[now][i].first;
            int cost = v[now][i].second;
            if(f_check(now, next, cost, K)) {
                visit[next] = visit[now] + cost;
                pq.push(make_pair(-visit[next], next));
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        if(visit[i] <= K) answer++;
    }
    return answer;
}