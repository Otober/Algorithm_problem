#include <string>
#include <vector>
#include <map>

using namespace std;

map < char, int > mp;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i = 0; i < skill.size(); i++) {
        mp.insert(make_pair(skill[i], i + 1));
    }
    
    for(int i = 0; i < skill_trees.size(); i++) {
        int idx = 1;
        bool flag = true;
        for(int j = 0; j < skill_trees[i].size(); j++) {
            char c = skill_trees[i][j];
            if(mp[c] == 0) continue;
            else if(mp[c] == idx) idx++;
            else {
                flag = false;
                break;
            }
        }
        if(flag) answer++;
    }
    return answer;
}