#include <string>
#include <vector>

using namespace std;

bool f_check(string st) {
    int sum = 0;
    for(int i = 0; i < st.size(); i++) {
        if(st[i] == '(') sum++;
        else sum--;
        if(sum < 0) return false;
    }
    return true;
}

string f_func(string st) {
    if(st.empty()) return st;
    
    int left = 0, right = 0;
    string u = "", v = "";
    for(int i = 0; i < st.size(); i++) {
        if(st[i] == '(') left++;
        else right++;
        if(left == right) {
            u = st.substr(0, i + 1);
            v = st.substr(i + 1);
            break;
        }
    }
    if(f_check(u)) return u + f_func(v);
    else {
        string temp = '(' + f_func(v) + ')';
        u = u.substr(1, u.size() - 2);
        for(int i = 0; i < u.size(); i++) {
            if(u[i] == '(') temp += ')';
            else temp += '(';
        }
        return temp;
    }
}

string solution(string p) {
    string answer = "";
    return answer = f_func(p);
}