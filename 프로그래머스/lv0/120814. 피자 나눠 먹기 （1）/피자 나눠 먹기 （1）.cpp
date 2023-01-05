#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i = 1;; i++) {
        if(i * 7 >= n) {
            answer = i;
            break;
        }
    }
    return answer;
}