#include <string>
#include <vector>
#include <stack>

#include <iostream>
using namespace std;

string f_calculation(int n, int index) {
    stack < int > st;
    if(index == 0) return "0";
    while(index > 0) {
        st.push(index % n);
        index /= n;
    }
    string str = "";
    while(!st.empty()) {
        if(st.top() == 10) str += "A";
        else if(st.top() == 11) str += "B";
        else if(st.top() == 12) str += "C";
        else if(st.top() == 13) str += "D";
        else if(st.top() == 14) str += "E";
        else if(st.top() == 15) str += "F";
        else str += to_string(st.top());
        st.pop();
    }
    return str;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int cnt = 0;
    int index = 0;
    string base = "";
    
    p--;
    
    while(answer.size() != t) {
        if(base.size() == 0) base = f_calculation(n, index++);
        if(cnt == p) answer += base[0];
        base.erase(base.begin());
        cnt++;
        if(cnt == m) cnt = 0;
    } 
    return answer;
}