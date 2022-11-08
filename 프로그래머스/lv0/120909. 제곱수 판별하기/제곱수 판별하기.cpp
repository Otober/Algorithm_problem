#include <string>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    double temp = sqrt(n);
    if(ceil(temp) == temp) answer = 1;
    else answer = 2;
    return answer;
}