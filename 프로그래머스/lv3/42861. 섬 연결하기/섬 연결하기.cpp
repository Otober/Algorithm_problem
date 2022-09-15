#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 105;
int visit[N] = {};

bool cmp(vector < int > &a, vector < int > &b) {
    return a[2] < b[2];
}

int f_group(int n) {
    while(n != visit[n]) n = visit[n];
    return n;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i = 0; i < n; i++) visit[i] = i;
    sort(costs.begin(), costs.end(), cmp);
    for(int i = 0; i < costs.size(); i++) {
        int a = costs[i][0];
        int b = costs[i][1];
        int cost = costs[i][2];
        
        int ga = f_group(a);
        int gb = f_group(b);
        if(ga == gb) continue;
        answer += cost;
        if(gb < ga) visit[ga] = gb;
        else visit[gb] = ga;
    }
    return answer;
}