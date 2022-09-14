#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool flag;
string str;
stack < char > st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    getline(cin, str);
    str += '\n';
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '<') {
            while(!st.empty()) {
                cout << st.top();
                st.pop();
            }
            cout << str[i];
            flag = true;
        }
        else if(str[i] == '>') {
            cout << str[i];
            flag = false;
        }
        else if(flag) {
            cout << str[i];
        }
        else if(str[i] == ' ' || str[i] == '\n') {
            while(!st.empty()) {
                cout << st.top();
                st.pop();
            }
            cout << " ";
        }
        else st.push(str[i]);
    }
    return 0;
}