#include <string>
#include <vector>
#include <cmath>

const int MAX = 1005;

using namespace std;

int solution(string s) {
    int answer = MAX;
    for(int i = 1; i <= s.size() / 2; i++) {
        string str = "";
        bool flag = false;
        int cnt = 0;
        int tcnt = 1;
        for(int j = 0; j <= (s.size() - 1) / i; j++) {
            if(str == s.substr(i * j, i)) {
                tcnt++;
                if(flag) {
                    flag = false;
                    cnt++;
                }
                if(tcnt != 0 && pow(10, (int)log10(tcnt)) == tcnt) cnt++;
            }
            else {
                str = s.substr(i * j, i);
                flag = true;
                cnt += str.size();
                tcnt = 1;
            }
        }
        answer = min(answer, cnt);
    }
    if(s.size() == 1) answer = 1;
    return answer;
}