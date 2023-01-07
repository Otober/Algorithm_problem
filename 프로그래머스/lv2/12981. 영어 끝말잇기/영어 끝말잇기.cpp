#include <string>
#include <vector>
#include <map>


using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map < string, bool > mp;
    char temp = words[0][words[0].size() - 1];
    mp.insert(make_pair(words[0], true));
    for(int i = 1; i < words.size(); i++) {
        if(temp != words[i][0]) {
            answer.push_back((i % n) + 1);
            answer.push_back((i / n) + 1);
            break;
        }
        else {
            if(mp.find(words[i]) == mp.end()) {
                mp.insert(make_pair(words[i], true));
                temp = words[i][words[i].size() - 1];
            }
            else {
                answer.push_back((i % n) + 1);
                answer.push_back((i / n) + 1);
                break;
            }
        }
    }
    if(answer.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}