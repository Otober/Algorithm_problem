#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = (numbers[0] + numbers[numbers.size() - 1]) /2.0;
    return answer;
}