#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    bool flag = true;
    while(flag) {
        flag = false;
        int temp = (n / a) * b;
        if(temp > 0) flag = true;
        answer += temp;
        n %= a;
        n += temp;
    }
    return answer;
}