#include <string>
#include <vector>
#include <queue>

using namespace std;

queue < string > q1, q2;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    for(int i = 0; i < cards1.size(); i++) {
        q1.push(cards1[i]);
    }
    for(int i = 0; i < cards2.size(); i++) {
        q2.push(cards2[i]);
    }
    for(int k = 0; k < goal.size(); k++) {
        string st1 = "", st2 = "";
        if(!q1.empty()) st1 = q1.front();
        if(!q2.empty()) st2 = q2.front();
        if(goal[k] == st1) {
            q1.pop();
        }
        else if(goal[k] == st2) {
            q2.pop();
        }
        else {
            answer = "No";
            break;
        }
    }
    return answer;
}