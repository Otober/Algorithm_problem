#include <string>
#include <vector>

using namespace std;

bool f_check(string &s) {
    for(int i = 0; i < s.size(); i++) {
        if(s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}

bool solution(string s) {
    bool answer = false;
    if((s.size() == 4 || s.size() == 6) && f_check(s)) answer = true;
    return answer;
}