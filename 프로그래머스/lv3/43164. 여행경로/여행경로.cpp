#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 10005;

vector < string > answer;
bool visit[N] = {};

bool f_dfs(vector < vector < string > > &tickets, vector < string > result, int depth, string now) {
    if(tickets.size() == depth) {
        answer = result;
        return true;
    }
    for(int i = 0; i < tickets.size(); i++) {
        if(tickets[i][0] == now && !visit[i]) {
            visit[i] = true;
            result.push_back(tickets[i][1]);
            if(f_dfs(tickets, result, depth + 1, tickets[i][1])) return true;
            result.pop_back();
            visit[i] = false;
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {

    sort(tickets.begin(), tickets.end());
    for(int i = 0; i < tickets.size(); i++) {
        if(tickets[i][0] == "ICN" && !visit[i]) {
            visit[i] = true;
            f_dfs(tickets, tickets[i], 1, tickets[i][1]);
            visit[i] = false;
        }
    }
    return answer;
}