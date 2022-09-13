#include <string>
#include <vector>
#include <stack>

using namespace std;

stack < char > st;

int solution(string s) {
    int answer = 0;
    string str = s;
    for (int k = 0; k < str.size(); k++) {
        bool flag = true;
        while (!st.empty()) {
            st.pop();
        }
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '[' || str[i] == '{' || str[i] == '(') st.push(str[i]);
            else {
                if (st.empty()) {
                    flag = false;
                    break;
                }
                else if (str[i] == ']') {
                    if (st.top() == '[') st.pop();
                    else {
                        flag = false;
                        break;
                    }
                }
                else if (str[i] == '}') {
                    if (st.top() == '{') st.pop();
                    else {
                        flag = false;
                        break;
                    }
                }
                else if (str[i] == ')') {
                    if (st.top() == '(') st.pop();
                    else {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if (flag && st.empty()) answer++;
        char temp = str[0];
        str.erase(str.begin());
        str += temp;
    }
    return answer;
}