#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1005;

vector < int > v[N];
queue < int > q;

int indegree[N] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    vector < int > answer;
    bool flag = false;
    cin >> n >> m;
    while(m--) {
        int pd;
        vector < int > temp;
        cin >> pd;
        for(int i = 0; i < pd; i++) {
            int t;
            cin >> t;
            temp.push_back(t);
        }
        for(int i = 0; i < temp.size(); i++) {
            for(int j = i + 1; j < temp.size(); j++) {
                v[temp[i]].push_back(temp[j]);
                indegree[temp[j]]++;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) q.push(i);
    }
    for(int i = 1; i <= n; i++) {
        if(q.empty()) {
            answer.clear();
            answer.push_back(0);
            break;
        }
        int now = q.front();
        answer.push_back(now);
        q.pop();
        for(int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];
            indegree[next]--;
            if(indegree[next] == 0) q.push(next);
        }
    }
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }
    return 0;
}