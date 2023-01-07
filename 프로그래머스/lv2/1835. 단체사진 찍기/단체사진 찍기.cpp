#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int N = 8;
const char kakao_friend[N] ={'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};

int answer = 0;
bool visit[N] = {};

void f_dfs(int cnt, char temp[], vector < string > &data) {
    if(cnt == N) {
        for(int i = 0; i < data.size(); i++) {
            char first = data[i][0];
            char second = data[i][2];
            char op = data[i][3];
            int num = (data[i][4] - '0');
            num++;
            
            int idx1 = -1;
            int idx2 = -1;
            for(int j = 0; j < N; j++) {
                if(temp[j] == first) idx1 = j;
                if(temp[j] == second) idx2 = j;
            }
            
            if(op == '=' && abs(idx1 - idx2) != num) return;
            if(op == '<' && abs(idx1 - idx2) >= num) return;
            if(op == '>' && abs(idx1 - idx2) <= num) return;
        }
        answer++;
        return;
    }
    else {
        for(int i = 0 ; i < N; i++) {
            if(visit[i]) continue;
            visit[i] = true;
            temp[cnt] = kakao_friend[i];
            f_dfs(cnt + 1, temp, data);
            visit[i] = false;
        }
    }
}

int solution(int n, vector<string> data) {
    char temp[N] = {};
    answer = 0;
    for(int i = 0; i < N; i++) {
        visit[i] = false;
    }
    f_dfs(0, temp, data);
    return answer;
}