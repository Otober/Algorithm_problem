#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int paint = -1;
    sort(section.begin(), section.end());
    for(int i = 0; i < section.size(); i++) {
        if(section[i] > paint) {
            answer++;
            paint = section[i] + m - 1;
        }
    }
    return answer;
}