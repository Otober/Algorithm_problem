#include <string>
#include <vector>

using namespace std;

const int N = 205;

bool visit[N] = {};

void f_dfs(int node, vector < vector < int > > &computers) {
    visit[node] = true;
    for(int i = 0; i < computers[node].size(); i++) {
        if(computers[node][i] == 1 && !visit[i]) f_dfs(i, computers);
    }
}

int solution(int n, vector < vector < int > > computers) {
    int answer = 0;
    for(int i = 0; i < n; i++) {
        if(!visit[i]) {
            answer++;
            f_dfs(i, computers);
        }
    }
    return answer;
}