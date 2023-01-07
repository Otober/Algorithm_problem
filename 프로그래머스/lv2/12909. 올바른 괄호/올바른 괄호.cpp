#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack < char > st;
    for(int i = 0; i < s.size(); i++) {
        if(st.empty()) {
            if(s[i] == ')') {
                answer = false;
                break;
            }
            else st.push(s[i]);
        }
        else {
            if(s[i] == '(') st.push(s[i]);
            else {
                char temp = st.top();
                if(temp == '(') st.pop();
                else {
                    answer = false;
                    break;
                }
            }
        }
    }
    if(!st.empty()) answer = false;
    return answer;
}