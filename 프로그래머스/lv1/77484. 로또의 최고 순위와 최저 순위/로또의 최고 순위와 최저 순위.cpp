#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zero = 0, cnt = 0;
    sort(lottos.begin(), lottos.end());
    for(int i = 0; i < lottos.size(); i++) {
        if(lottos[i] == 0) zero++;
        else {
            if(find(win_nums.begin(), win_nums.end(), lottos[i]) != win_nums.end()) {
                cnt++;
            }
        }
    }
    if(cnt + zero > 1) answer.push_back(7 - (cnt + zero));
    else answer.push_back(6);
    if(cnt > 1) answer.push_back(7 - (cnt));
    else answer.push_back(6);
    return answer;
}