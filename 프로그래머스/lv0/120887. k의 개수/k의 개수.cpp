#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int c) {
    int answer = 0;
    for(int i = a; i <= b; i++) {
        int n = i;
        while(n > 0) {
            if(n % 10 == c) answer++;
            n /= 10;
        }
    }
    return answer;
}