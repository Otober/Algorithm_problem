#include <string>
#include <vector>

using namespace std;

const int N = 60005;
const int devive = 1000000007;

int visit[N] = {};

int solution(int n) {
    int answer = 0;
    visit[1] = 1;
    visit[2] = 2;
    for(int i = 3; i <= n; i++) {
        visit[i] = (visit[i - 1] + visit[ i -2]) % devive;
    }
    return answer = visit[n];
}