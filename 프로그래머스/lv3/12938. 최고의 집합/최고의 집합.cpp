#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n > s) answer.push_back(-1);
    else {
        answer.resize(n);
        for(int i = 0; i < n; i++) {
            answer[i] = s / n;
        }
        int temp = s % n;
        for(int i = answer.size(); i >= 0; i--) {
            if(temp) {
                answer[i - 1]++;
                temp--;
            }
            else break;
        }
    }
    return answer;
}