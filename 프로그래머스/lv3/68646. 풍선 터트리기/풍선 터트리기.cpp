#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 2;
    int left = a[0];
    int right = a[a.size() - 1];
    for(int i = 1; i < a.size() - 1; i++) {
        if(left > a[i]) {
            left = a[i];
            answer++;
        }
        if(right > a[a.size() - 1 - i]) {
            right = a[a.size() - 1 - i];
            answer++;
        }
    }
    return (left == right) ? answer - 1 : answer;
}