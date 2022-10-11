#include <string>
#include <vector>

using namespace std;

const int N = 300005;

long long answer = 0;

bool visit[N] = {};

vector < long long > val;

vector < long long > v[N];

void f_dfs(int child, int parent) {
    visit[child] = true;
    for(int i = 0; i < v[child].size(); i++) {
        int next = v[child][i];
        if(!visit[next]) {
            f_dfs(v[child][i], child);
        }
    }
    if(parent == -1) return;
    answer += abs(val[child]);
    val[parent] += val[child];
    val[child] -= val[child];
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    
    for(int i = 0; i < a.size(); i++) {
        val.push_back(a[i]);
    }
    for(int i = 0; i < edges.size(); i++) {
        v[edges[i][0]].push_back(edges[i][1]);
        v[edges[i][1]].push_back(edges[i][0]);
    }
    visit[0] = true;
    f_dfs(0, -1);
    if(val[0] != 0) answer = -1;
    return answer;
}