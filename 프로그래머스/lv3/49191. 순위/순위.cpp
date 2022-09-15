#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const int N = 105;

int v[N][N] = {};

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(int i = 0; i < results.size(); i++) {
        v[results[i][0]][results[i][1]] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                if(v[j][i] == 1 && v[i][k]) v[j][k] = 1;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        for(int j = 1; j <= n; j++) {
            cnt += v[i][j] + v[j][i];
        }
        if(cnt == n - 1) answer++;
    }
    return answer;
}