#include <string>
#include <vector>

#include <iostream>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    for(int k = 0; k < s.size(); k++) {
        string str = s[k];
        int cnt = 0;
        for(int i = 0; i < (int)str.size() - 2; i++) {
            if(str[i] == '1' && str[i + 1] == '1' && str[i + 2] == '0') {
                str.erase(i, 1);
                str.erase(i, 1);
                str.erase(i, 1);
                cnt++;
                i -= 3;
            }
        }
        if(cnt != 0) {
            int idx = str.size() - 1;
            while(idx >= 0 && str[idx] == '1') {
                idx--;
            }
            for(int i = 0; i < cnt; i++) {
                str.insert(idx + 1, "110");
            }
        }
        answer.push_back(str);
    }
    return answer;
}