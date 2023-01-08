#include <string>
#include <vector>
#include <cmath>

using namespace std;

const int alphabets = 26;

int solution(string name) {
    int answer = 0;
    int len = name.size();
    for(int i = 0; i < len; i++) {
        int temp = (name[i] - 'A' < alphabets - (name[i] - 'A')) ? name[i] - 'A' : alphabets - (name[i] - 'A');
        answer += temp;
    }
    
    int left_right = len - 1;
    for (int i = 0; i < len; i++) {
        int next_i = i + 1;
        while (next_i < len && name[next_i] == 'A') {
            next_i++;
        }
        left_right = min(left_right, i + len - next_i + min(i, len - next_i));
    }
    answer += left_right;
    return answer;
}