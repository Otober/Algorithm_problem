#include <string>
#include <vector>

#include <iostream>

using namespace std;

vector < int > v;

int solution(int n) {
    int answer = 0;
    while(n > 0) {
        v.push_back(n % 3);
        n /= 3;
    }
    int temp = 1;
    for(int i = v.size() - 1; i >= 0; i--) {
        answer += v[i] * temp;
        temp *= 3;
    }
    return answer;
}