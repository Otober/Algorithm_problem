#include <string>
#include <vector>

using namespace std;

const int N = 10;

int tcnt = 0;

bool visit[N] = {}; 

void f_dfs(int k, int cnt, vector<vector<int>> dungeons) {
    for(int i = 0; i < dungeons.size(); i++) {
        if(visit[i] == false && k >= dungeons[i][0]) {
            visit[i] = true;
            f_dfs(k - dungeons[i][1], cnt + 1, dungeons);
            visit[i] = false;
        }
        if(i == dungeons.size() - 1) {
            if(tcnt < cnt) tcnt = cnt;
        } 
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    for(int i = 0; i < dungeons.size(); i++) {
        if(k >= dungeons[i][0]) {
            visit[i] = true;
            f_dfs(k - dungeons[i][1], 1, dungeons);
            visit[i] = false;
        }
    }
    answer = tcnt;
    return answer;
}