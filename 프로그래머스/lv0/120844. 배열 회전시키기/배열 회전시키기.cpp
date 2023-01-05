#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    vector<int> answer = numbers;
    if(direction == "right") {
        int temp = answer[answer.size() - 1];
        answer.erase(answer.end() - 1);
        answer.insert(answer.begin(), temp);
    }
    else {
        int temp = answer[0];
        answer.erase(answer.begin());
        answer.push_back(temp);
    }
    return answer;
}