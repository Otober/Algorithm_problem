#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;
string ans;

stack < char > st;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> str;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') ans += str[i];
        else {
            switch(str[i]) {
                case '(' :
                    st.push(str[i]);
                    break;
                case '*' :
                case '/' :
                    while(!st.empty() && (st.top() == '*' || st.top() == '/')) {
                        ans += st.top();
                        st.pop();
                    }
                    st.push(str[i]);
                    break;
                
                case '+' :
                case '-' :
                    while(!st.empty() && st.top() != '(') {
                        ans += st.top();
                        st.pop();
                    }
                    st.push(str[i]);
                    break;
                
                case ')' :
                    while(!st.empty() && st.top() != '(') {
                        ans += st.top();
                        st.pop();
                    }
                    st.pop();
                    break;
            }
        }
    }
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    cout << ans;
    return 0;
}