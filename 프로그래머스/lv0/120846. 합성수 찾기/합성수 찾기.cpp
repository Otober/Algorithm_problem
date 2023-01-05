#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i = 4; i <= n; i++) {
        int temp = 2;
        for(int j = 2; j<= i / 2; j++) {
            if(i % j == 0) temp++;
            if(temp >= 3) break;
        }
        if(temp >= 3) answer++;
    }
    return answer;
}