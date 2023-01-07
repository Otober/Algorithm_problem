#include <string>
#include <vector>

using namespace std;

int binary(int n) {
    int cnt = 0;
    while(n > 0) {
        if(n % 2 == 1) cnt++;
        n /= 2;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    int tcnt = binary(n);
    while(true) {
        n++;
        if(tcnt == binary(n)) {
            answer = n;
            break;
        }
    }
    return answer;
}