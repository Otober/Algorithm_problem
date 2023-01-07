#include <string>
#include <vector>

using namespace std;

int answer = 0;

vector < int > v(3);

bool f_check() {
    int sum = 0;
    for(int i = 0; i < 3; i++) {
        sum += v[i];
    }
    if(sum == 0) return true;
    else return false;
}

void f_combination(int depth, int next, vector < int > &number) {
    if(depth == 3) {
        if(f_check()) answer++;
        return;
    }
    for(int i = next; i < number.size(); i++) {
        v[depth] = number[i];
        f_combination(depth + 1, i + 1, number);
    }
}

int solution(vector<int> number) {
    f_combination(0, 0, number);
    return answer;
}