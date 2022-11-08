#include <string>
#include <vector>

using namespace std;

const int alphabet = 26;

string solution(string s, int n) {
    string answer = "";
    for(int i = 0; i < s.size(); i++) {
        if('a' <= s[i] && s[i] <= 'z') {
            if(s[i] + n > 'z') answer += s[i] + n - alphabet;
            else answer += s[i] + n;
        }
        else if('A' <= s[i] && s[i] <= 'Z') {
            if(s[i] + n > 'Z') answer += s[i] + n - alphabet;
            else answer += s[i] + n;
        }
        else answer += " ";
    }
    return answer;
}