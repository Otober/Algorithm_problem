#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

const int N = 105;

bool visit[N] = {};

vector < int > v;

void f_dfs(int node, int cnt, vector<int> &cards) {
    if(visit[node]) {
        v.push_back(cnt);
        return;
    }
    else {
        visit[node] = true;
        f_dfs(cards[node], cnt + 1, cards);
    }
}

int solution(vector<int> cards) {
    int answer = 0;
    
    cards.insert(cards.begin(), -1);
    
    for(int i = 1; i < cards.size(); i++) {
        if(visit[i] == false) {
            visit[i] = true;
            f_dfs(cards[i], 1, cards);
        }
    }
    sort(v.begin(), v.end(), greater<>());
    if(v.size() == 1) answer = 0;
    else answer = v[0] * v[1];
    return answer;
}