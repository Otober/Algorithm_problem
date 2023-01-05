#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int temp = 0, temp2;
    bool sign = true;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '-') sign = false;
        else if(s[i] >= '0' && s[i] <= '9') {
            temp *= 10;
            temp += s[i] - '0';
        }
        else if(s[i] == ' ') {
            if(sign == false) {
                temp = -temp;
                sign = true;
            }
            temp2 = temp;
            answer += temp;
            temp = 0;
        }
        else if(s[i] == 'Z') {
            answer -= temp2;
        }
    }
    if(sign == false) temp = -temp;
    answer += temp;
    return answer;
}