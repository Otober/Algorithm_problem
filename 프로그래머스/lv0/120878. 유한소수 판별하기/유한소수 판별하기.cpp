#include <string>
#include <vector>

using namespace std;

int f_gcd(int a, int b) {
    if(b == 0)return a;
    else return f_gcd(b, a % b);
}

int solution(int a, int b) {
    int answer = 0;
    int gcd = f_gcd(a, b);
    a /= gcd;
    b /= gcd;
    bool flag = true;
    while(flag) {
        flag = false;
        if(b % 2 == 0) {
            b /= 2;
            flag = true;
        }
        if(b % 5 == 0) {
            b /= 5;
            flag = true;
        }
    }
    if(b == 1) answer = 1;
    else answer = 2;
    return answer;
}