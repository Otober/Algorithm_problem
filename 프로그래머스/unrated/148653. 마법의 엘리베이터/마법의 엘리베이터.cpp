#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    while(storey) {
        int temp = storey % 10;
        if(temp < 5) {
            answer += temp;
            storey /= 10;
        }
        else if(temp > 5) {
            answer += (10 - temp);
            storey /= 10;
            storey += 1;
        }
        else if(temp == 5) {
            int temp_5 = (storey % 100) / 10;
            if(temp_5 >= 5) {
                answer += (10 - temp);
                storey /= 10;
                storey += 1;
            }
            else {
                answer += temp;
                storey /= 10;
            }
        }
    }
    return answer;
}