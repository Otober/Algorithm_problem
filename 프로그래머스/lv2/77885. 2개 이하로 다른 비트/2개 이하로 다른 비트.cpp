#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(int i = 0; i < numbers.size(); i++) {
        if(numbers[i] % 2 == 0) answer.push_back(numbers[i] + 1);
        else {
            unsigned long long bit = 1;
            while(true) {
                if(!(bit & numbers[i])) break;
                bit *= 2;
            }
            long long temp = numbers[i];
            temp = temp | bit;
            bit /= 2;
            temp = temp & ~bit;
            answer.push_back(temp);
            
        }
    }
    return answer;
}