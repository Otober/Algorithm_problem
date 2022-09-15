#include <string>
#include <vector>
#include <set>

using namespace std;

const int N = 10;

set < string > s;

bool visit[N] = {};

void f_except(vector < string > &user, vector < string > &banned, int index) {
    if(index == banned.size()) {
        string temp = "";
        for(int i = 0; i < user.size(); i++) {
            if(visit[i]) temp += user[i];
        }
        s.insert(temp);
        return;
    }
    
    for(int i = 0; i < user.size(); i++) {
        bool flag = true;
        if(visit[i]) continue;
        if(user[i].size() != banned[index].size()) continue;
        
        for(int j = 0; j < banned[index].size(); j++) {
            if(banned[index][j] == '*') continue;
            if(user[i][j] != banned[index][j]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            visit[i] = true;
            f_except(user, banned, index + 1);
            visit[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    f_except(user_id, banned_id, 0);
    return answer = s.size();
}