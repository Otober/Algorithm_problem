#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    if((int)sqrt(n) == sqrt(n)) answer = pow((int)sqrt(n) + 1, 2);
    else answer = -1;
    return answer;
}