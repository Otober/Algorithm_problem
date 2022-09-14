#include <iostream>
#include <string>
#include <stack>

using namespace std;

const int Alphabets = 26;

int arr[Alphabets] = {};

string str;

stack < double > st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    cin >> str;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for(int i = 0; i < str.size(); i++) {
        char c = str[i];
        
        if(c >= 'A' && c <= 'Z') {
            st.push((double)arr[(c - 'A')]);
        }
        else {
            double b = st.top();
            st.pop();
            double a = st.top();
            st.pop();
            
            if(c == '+') st.push(a + b);
            else if(c == '-') st.push(a - b);
            else if(c == '*') st.push(a * b);
            else if(c == '/') st.push(a / b);
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << st.top();
    return 0;
}