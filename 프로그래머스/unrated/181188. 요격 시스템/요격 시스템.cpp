#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 500005;

bool visit[N] = {};

pair <int, int > p[N];

bool cmp(pair < int, int > &a, pair < int, int > &b) {
    return a.second < b.second;
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int n = targets.size();
    for(int i = 0; i < targets.size(); i++) {
        p[i] = make_pair(targets[i][0], targets[i][1]);
    }
    sort(p, p + n, cmp);
    for(int i = 0; i < n; i++) {
        if(!visit[i]) {
            answer++;
            for(int j = i + 1; j < n ; j++) {
                if(p[i].second > p[j].first) visit[j] = true;
            }
            visit[i] = true;
        }
    }
    return answer;
}