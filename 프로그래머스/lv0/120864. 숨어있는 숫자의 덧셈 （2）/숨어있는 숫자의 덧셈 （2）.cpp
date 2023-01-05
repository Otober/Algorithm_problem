#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    int temp = 0;
    for(int i = 0; i < my_string.size(); i++) {
        if(my_string[i] >= '0' && my_string[i] <= '9') {
            temp *= 10;
            temp += my_string[i] - '0';
        }
        else {
            answer += temp;
            temp = 0;
        }
    }
    answer += temp;
    return answer;
}