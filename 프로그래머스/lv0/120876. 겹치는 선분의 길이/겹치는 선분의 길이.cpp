#include <string>
#include <vector>

using namespace std;

const int N = 105;

bool visit[2 * N] = {};

int solution(vector<vector<int>> lines) {
    int answer = 0;
    for(int i = 0; i < lines.size(); i++) {
        if(lines[i][0] > lines[i][1]) {
            int temp = lines[i][0];
            lines[i][0] = lines[i][1];
            lines[i][1] = temp;
        }
    }
    for(int i = 0; i < lines.size(); i++) {
        for(int j = i + 1; j < lines.size(); j++) {
            int t_max = (lines[i][1] > lines[j][1]) ? lines[j][1] : lines[i][1];
            int t_min = (lines[i][0] > lines[j][0]) ? lines[i][0] : lines[j][0];
            for(int i = t_min + 1; i <= t_max; i++) {
                if(visit[i + 100] == false) {
                    answer++;
                    visit[i + 100] = true;
                }
            }
        }
    }
    return answer;
}