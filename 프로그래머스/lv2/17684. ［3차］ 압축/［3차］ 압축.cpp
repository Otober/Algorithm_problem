#include <string>
#include <vector>
#include <map>

using namespace std;

map < string, int > m;

void f_initialize() {
    for(int i = 0; i < 26; i++) {
        m.insert(make_pair(string(1, i + 'A'), i + 1));
    }
}

vector<int> solution(string msg) {
    vector<int> answer;
    f_initialize();
    int cnt = 1;
    int idx = 27;
    for(int i = 0; i < msg.size(); i++) {
        for(int j = cnt; j > 0; j--) {
            if(i + j > msg.size()) continue;
            string temp = msg.substr(i, j);
            if(m.find(temp) != m.end()) {
                int index = m.find(temp)->second;
                answer.push_back(index);
                temp += msg[i + j];
                i += j - 1;
                m.insert(make_pair(temp, idx++));
                if(cnt < temp.size()) cnt = temp.size();
                break;
            }
        }
    }
    return answer;
}