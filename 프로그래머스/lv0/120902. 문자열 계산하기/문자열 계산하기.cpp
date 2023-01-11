#include <string>
#include <vector>
#include <deque>

using namespace std;

deque < int > num;
deque < bool > op;

bool f_check(char c) {
    if(c >= '0' && c <= '9') return true;
    else return false;
}

int solution(string my_string) {
    int answer = 0;
    int index = 0;
    while(index < my_string.size()) {
        if(f_check(my_string[index])) {
            int temp = 0;
            while(f_check(my_string[index])) {
                temp *= 10;
                temp += my_string[index] - '0';
                index++;
            }
            num.push_back(temp);
        }
        else {
            if(my_string[index] == '+') op.push_back(true);
            else if(my_string[index] == '-') op.push_back(false);
            index++;
        }
    }
    while(!op.empty()) {
        int num1 = num[0];
        int num2 = num[1];
        bool oper = op[0];
        num.pop_front();
        num.pop_front();
        op.pop_front();
        
        if(oper) num.push_front(num1 + num2);
        else num.push_front(num1 - num2);
    }
    return answer = num[0];
}