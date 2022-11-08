#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int answer = 0;
    int index = 1;
    while(num > 0) {
        if(num % 10 == k) answer = index;
        num /= 10;
        index++;
    }
    if(answer == 0) answer = -1;
    else answer = index - answer;
    return answer;
}