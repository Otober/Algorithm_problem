#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector < int > arr;
    while(n > 0) {
        arr.push_back(n % 10);
        n /= 10;
    }
    sort(arr.begin(), arr.end());
    while(!arr.empty()) {
        answer *= 10;
        answer += arr.back();
        arr.pop_back();
    }
    return answer;
}