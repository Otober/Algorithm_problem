#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx = -1;
    for(int i = 0; i < s.size(); i++) {
        idx++;
        if(s[i] == ' ') idx = -1;
        
        if(idx % 2 == 0) answer += toupper(s[i]);
        else answer += tolower(s[i]);
    }
    return answer;
}