#include <vector>
using namespace std;

const int N = 100005;

int dy[N][4] = {};

int solution(vector<vector<int> > land)
{
    int answer = 0;
    for(int i = 0; i < 4; i++) {
        dy[0][i] = land[0][i];
    }
    for(int i = 1; i < land.size(); i++) {
        for(int j = 0; j < land[i].size(); j++) {
            for(int k = 0; k < land[i].size(); k++) {
                if(j == k) continue;
                dy[i][j] = max(dy[i][j], dy[i - 1][k] + land[i][j]);
            }
        }
    }
    for(int i = 0; i < 4; i++) {
        answer = max(answer,dy[land.size() - 1][i]);
    }
    return answer;
}