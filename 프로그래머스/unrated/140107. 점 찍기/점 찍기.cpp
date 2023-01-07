#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    for(long long i = 0; i <= d; i += k) {
        long long y_max = floor(sqrt((long long)d * d - i * i));
        answer += (y_max / k) + 1;
    }
    return answer;
}