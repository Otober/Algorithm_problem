#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int len = number.length() - k;
    int st = 0;
    int st_max = -1;
    while(answer.length() != number.length() - k) {
        for(int i = st; i <= number.length() - len; i++) {
            if(st_max < number[i] - '0') {
                st_max = number[i] - '0';
                st = i;
            }
        }
        answer += number[st];
        st_max = -1;
        st++;
        len--;
    }
    return answer;
}