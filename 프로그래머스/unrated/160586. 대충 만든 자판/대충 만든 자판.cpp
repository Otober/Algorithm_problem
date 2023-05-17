#include <string>
#include <vector>
#include <map>

using namespace std;

map < char, int > m;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    for(int i = 0; i < keymap.size(); i++) {
        for(int j = 0; j < keymap[i].size(); j++) {
            char temp = keymap[i][j];
            if(m.find(temp) == m.end()) m.insert(make_pair(temp, j + 1));
            else if(m[temp] > j) m[temp] = j + 1;
        }
    }
    for(int i = 0; i < targets.size(); i++) {
        int cnt = 0;
        for(int j = 0; j < targets[i].size(); j++) {
            if(m.find(targets[i][j]) == m.end()) {
                cnt = -1;
                break;
            }
            else {
                cnt += m.find(targets[i][j])->second;
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}