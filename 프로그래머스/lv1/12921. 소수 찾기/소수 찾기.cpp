#include <string>
#include <vector>

using namespace std;

const int N = 1000005;

bool visit[N] = {};

int solution(int n) {
    int answer = 0;
    for(int i = 2; i <= n / 2; i++) {
        int temp = i;
        for(int j = 2; j * temp <= n; j++) {
            visit[j * temp] = true;
        }
    }
    for(int i = 2; i <= n; i++) {
        if(visit[i] == false) answer++;
    }
    return answer;
}