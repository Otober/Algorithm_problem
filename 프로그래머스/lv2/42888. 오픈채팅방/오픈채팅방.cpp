#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map < string, string > mp;
    vector < pair < string, bool > > v;
    
    for(int i = 0; i < record.size(); i++) {
        string order, id, nickname;
        int j = 0;
        int temp = 0;
        for(; j < record[i].size(); j++) {
            if(record[i][j] == ' ') {
                order = record[i].substr(temp, j - temp);
                temp = j + 1;
                j++;
                break;
            }
        }
        for(; j < record[i].size(); j++) {
            if(record[i][j] == ' ') {
                id = record[i].substr(temp, j - temp);
                temp = j + 1;
                j++;
                break;
            }
            else if(j == record[i].size() - 1) {
                id = record[i].substr(temp);
                break;
            }
        }
        if(order == "Enter" || order == "Change") {
            nickname = record[i].substr(temp);
        }
        if(order == "Enter" || order == "Change") {
            if(mp.find(id) == mp.end()) mp.insert(make_pair(id, nickname));
            else {
                mp.erase(id);
                mp.insert(make_pair(id, nickname));
            }
        }
        if(order == "Enter" || order == "Leave") {
            v.push_back(make_pair(id, (order == "Enter") ? true : false));
        }
    }
    
    for(int i = 0; i < v.size(); i++) {
        string id = v[i].first;
        bool condition = v[i].second;
        string temp = mp[id];
        
        if(condition == true) temp += "님이 들어왔습니다.";
        else temp += "님이 나갔습니다.";
        answer.push_back(temp);
    }
    return answer;
}