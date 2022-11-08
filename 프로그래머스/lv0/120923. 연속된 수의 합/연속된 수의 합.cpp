#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    if(num % 2 == 1) {
        int n = total / num;
        for(int i = n - num/2; i <= n + num / 2; i++) {
            answer.push_back(i);
        }
    }
    else {
        int n = total / num;
        for(int i = n - num/2 + 1; i <= n + num / 2; i++) {
            answer.push_back(i);
        }
    }
    return answer;
}