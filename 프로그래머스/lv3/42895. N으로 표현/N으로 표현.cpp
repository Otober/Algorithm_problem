// 문제가 개편되었습니다. 이로 인해 함수 구성이나 테스트케이스가 변경되어, 과거의 코드는 동작하지 않을 수 있습니다.
// 새로운 함수 구성을 적용하려면 [코드 초기화] 버튼을 누르세요. 단, [코드 초기화] 버튼을 누르면 작성 중인 코드는 사라집니다.
#include <string>
#include <vector>

using namespace std;

const int MAX = 9;

int use_min = MAX;

void f_dfs(int N, int number, int depth, int num) {
    if(depth >= MAX) return ;
    if(num == number) use_min = min(depth, use_min);
    
    int temp = 0;
    for(int i = 1; i <= MAX; i++) {
        temp = temp * 10 + N;
        f_dfs(N, number, depth + i, num + temp);
        f_dfs(N, number, depth + i, num - temp);
        if(num != 0) {
            f_dfs(N, number, depth + i, num * temp);
            f_dfs(N, number, depth + i, num / temp);
        }
    }
}

int solution(int N, int number) {
    int answer = 0;
    f_dfs(N, number, 0, 0);
    answer = ((use_min) >= MAX ? -1 : use_min);
    return answer;
}