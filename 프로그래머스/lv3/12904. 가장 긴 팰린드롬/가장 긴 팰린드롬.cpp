#include <iostream>
#include <string>

using namespace std;

int solution(string s) {
    int answer = 0;
    for(int i = 0; i < s.size(); i++) {
        int left = i;
        int right = i;
        int len = -1;
        while(left >= 0 && right < s.size()) {
            if(s[left] != s[right]) break;
            len += 2;
            left--;
            right++;
        }
        answer = (len > answer) ? len : answer;
    }
    for(int i = 0; i < s.size() - 1; i++) {
        if(s[i] == s[i + 1]) {
            int left = i;
            int right = i + 1;
            int len = 0;
            while(left >= 0 && right < s.size()) {
                if(s[left] != s[right]) break;
                len += 2;
                left--;
                right++;
            }
            answer = (len > answer) ? len : answer;
        }
    }
    return answer;
}