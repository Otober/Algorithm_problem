#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = s;
    bool flag = true;
    for(int i = 0; i < s.size(); i++) {
        if(answer[i] == ' ') flag = true;
        else if(answer[i] >= '0' && answer[i] <= '9') flag = false;
        else if(flag) {
            if(answer[i] >= 'a' && answer[i] <= 'z') answer[i] = answer[i] - ('a' - 'A');
            flag = false;
        }
        else if(!flag) {
            if(answer[i] >= 'A' && answer[i] <= 'Z') answer[i] = answer[i] + ('a' - 'A');
        }
        cout << answer[i];
    }
    return answer;
}