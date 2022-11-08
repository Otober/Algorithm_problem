#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    for(int i = 0; i < db.size(); i++) {
        if(db[i][0].compare(id_pw[0]) == 0) {
            if(db[i][1].compare(id_pw[1]) == 0) answer = "login";
            else answer = "wrong pw";
            break;
        }
        else if(db.size() - 1 == i) answer = "fail";
    }
    return answer;
}