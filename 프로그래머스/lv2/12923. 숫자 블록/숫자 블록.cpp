#include <string>
#include <vector>
#include <cmath>

using namespace std;

int f_check(long long k) {
    long long t_k = sqrt(k);
    for(long long i = 2; i <= t_k; i++) {
        if(k % i == 0 && k / i <= 10000000) return k / i;
    }
    return 1;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for(long long k = begin; k <= end; k++) {
        answer.push_back(f_check(k));
    }
    if(begin == 1) answer[0] = 0;
    return answer;
}