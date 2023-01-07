#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool visit[3] = {};
char priority[3] = {};

long long answer = 0;

void f_mix(int cnt, vector < long long > num_original, vector < char > op_original) {
    if(cnt == 3) {
        vector < long long > num = num_original;
        vector < char > op = op_original;
       for(int i = 0; i < 3; i++) {
           for(int j = 0;  j < op.size(); j++) {
               if(priority[i] == op[j]) {
                   if(op[j] == '+') num[j] = num[j] + num[j + 1];
                   else if(op[j] == '-') num[j] = num[j] - num[j + 1];
                   else num[j] = num[j] * num[j + 1];
                   
                   op.erase(op.begin() + j);
                   num.erase(num.begin() + j + 1);
                   j--;
               }
           }
       }
        answer = max(answer, abs(num[0]));
        return;
    }
    else {
        for(int i = 0; i < 3; i++) {
            if(visit[i] == false) {
                visit[i] = true;
                if(i == 0) priority[cnt] = '+';
                else if(i == 1) priority[cnt] = '-';
                else priority[cnt] = '*';
                f_mix(cnt + 1, num_original, op_original);
                visit[i] = false;
            }
        }
    }
} 

long long solution(string expression) {
    vector < long long > num;
    vector < char > op;
    string temp = "";
    for(int i = 0; i < expression.size(); i++) {
        if(expression[i] >= '0' && expression[i] <= '9') temp += expression[i];
        else {
            num.push_back(stoll(temp));
            temp = "";
            op.push_back(expression[i]);
        }
    }
    num.push_back(stoll(temp));
    f_mix(0, num, op);
    return answer;
}