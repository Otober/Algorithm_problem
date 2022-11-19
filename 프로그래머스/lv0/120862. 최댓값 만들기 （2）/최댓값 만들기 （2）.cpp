#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = -987654321;
    int n = numbers.size();
    sort(numbers.begin(), numbers.end());
    if(numbers[0] * numbers[1] > answer) answer = numbers[0] * numbers[1];
    if(numbers[n - 1] * numbers[n - 2] > answer) answer = numbers[n - 1] * numbers[n - 2];
    return answer;
}