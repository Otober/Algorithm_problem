#include <string>
#include <vector>
#include <map>

using namespace std;

map < string, int > m;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int index = 10;
    if(index > discount.size()) index = discount.size();
    for(int i = 0; i < index; i++) {
        map < string, int >::iterator iter = m.find(discount[i]);
        if(iter == m.end()) m.insert(make_pair(discount[i], 1));
        else {
            iter->second += 1;
        }
    }
    while(true) {
        bool flag = true;
        for(int i = 0; i < want.size(); i++) {
            auto iter = m.find(want[i]);
            if(iter == m.end()||iter->second < number[i]) {
                flag = false;
                break;
            }
        }
        if(flag) answer++;
        if(index >= discount.size()) break;
        map < string, int >::iterator iter = m.find(discount[index]);
        if(iter == m.end()) m.insert(make_pair(discount[index], 1));
        else {
            iter->second += 1;
        }
        iter = m.find(discount[index - 10]);
        iter-> second -= 1;
        index++;
    }
    return answer;
}