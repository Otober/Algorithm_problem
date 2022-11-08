#include <string>
#include <vector>

using namespace std;

const int N = 26;

int before_arr[N] = {};
int after_arr[N] = {};


int solution(string before, string after) {
    int answer = 1;
    for(int i = 0; i < before.size(); i++) {
        before_arr[before[i] - 'a']++;
    }
    for(int i = 0; i < after.size(); i++) {
        after_arr[after[i] - 'a']++;
    }
    for(int i = 0; i < N; i++) {
        if(before_arr[i] != after_arr[i]) {
            answer = 0;
            break;
        }
    }
    return answer;
}