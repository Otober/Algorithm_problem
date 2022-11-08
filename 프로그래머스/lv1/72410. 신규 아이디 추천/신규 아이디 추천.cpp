#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool f_check_char(char c) {
    if(c >= 'a' && c <= 'z') return false;
    if(c >= '0' && c <= '9') return false;
    if(c == '-') return false;
    if(c == '_') return false;
    if(c == '.') return false;
    return true;
}

string solution(string new_id) {
    string answer = "";
    for(int i = 0; i < new_id.size(); i++) {
        if(new_id[i] >= 'A' && new_id[i] <= 'Z') new_id[i] = new_id[i] - 'A' + 'a';
    }
    for(int i = 0; i < new_id.size(); i++) {
        if(f_check_char(new_id[i])) {
            new_id.erase(i, 1);
            i--;
        }
    }
    for(int i = 0; i < new_id.size() - 1; i++) {
        if(new_id[i] == '.' && new_id[i + 1] == '.') {
            new_id.erase(i, 1);
            i--;
        }
    }
    if(new_id[0] == '.') new_id.erase(0, 1);
    if(new_id[new_id.length() - 1] == '.') new_id.erase(new_id.length() - 1, 1);
    if(new_id.length() == 0) new_id += "a";
    if(new_id.length() >= 16) new_id = new_id.substr(0, 15);
    if(new_id[new_id.length() - 1] == '.') new_id.erase(new_id.length() - 1, 1);
    if(new_id.length() <= 2) {
        while(new_id.length() != 3) {
            new_id += new_id[new_id.length() - 1];
        }
    }
    answer = new_id;
    return answer;
}