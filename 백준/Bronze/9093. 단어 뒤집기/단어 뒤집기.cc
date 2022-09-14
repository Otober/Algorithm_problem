#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        stack < char > st;
        string str;
        getline(cin, str);
        str += '\n';
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == ' ' || str[i] == '\n') {
                while(!st.empty()) {
                    cout << st.top();
                    st.pop();
                }
                cout << " ";
            }
            else st.push(str[i]);
        }
        cout << "\n";
    }
    return 0;
}