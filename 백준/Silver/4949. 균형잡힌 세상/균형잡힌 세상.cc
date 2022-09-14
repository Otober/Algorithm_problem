#include <iostream>
#include <string>
#include <stack>
#define N 105

using namespace std;

int main() {
    while(true) {
        string str;
        stack < char > st;
        getline(cin, str);
        if(!str.compare(".")) break;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '(' || str[i] == '[') st.push(str[i]);
            else if(str[i] == ')') {
                if(!st.empty() && st.top() == '(') st.pop();
                else {
                    cout << "no" << endl;
                    break;
                }
            }
            else if(str[i] == ']') {
                if(!st.empty() && st.top() == '[') st.pop();
                else {
                    cout << "no" << endl;
                    break;
                }
            }
            if(i == str.size() - 1) {
                if(st.empty()) cout << "yes" << endl;
                else cout << "no" << endl;
            }
        }
    }
    return 0;
}