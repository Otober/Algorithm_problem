#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(long long k = left; k <= right; k++) {
        long long i = k / n;
        long long j = k % n;
        long long temp = (i > j) ? i : j;
        answer.push_back(temp + 1);
    }
    return answer;
}