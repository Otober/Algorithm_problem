#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2);
    int cnt = 0, tcnt = 0;
    while(s != "1") {
        tcnt++;
        cnt = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') {
                cnt++;
                s.erase(s.begin() + i);
                i--;
            }
        }
        answer[1] += cnt;
        int temp = s.size();
        s.clear();
        while(temp > 0) {
            s += to_string(temp % 2);
            temp /= 2;
        }
        reverse(s.begin(), s.end());
        cout << s << "\n";
    }
    answer[0] = tcnt;
    return answer;
}