#include <string>
#include <vector>

using namespace std;

int answer = 0;

void f_dfs(vector < int > numbers, int target, int depth, int num, int i) {
    if(depth >= numbers.size()) {
        if(target == num) answer++;
        return;
    }
    f_dfs(numbers, target, depth + 1, num + numbers[i], i + 1);
    f_dfs(numbers, target, depth + 1, num - numbers[i], i + 1);
}

int solution(vector<int> numbers, int target) {
    f_dfs(numbers, target, 0, 0, 0);
    return answer;
}