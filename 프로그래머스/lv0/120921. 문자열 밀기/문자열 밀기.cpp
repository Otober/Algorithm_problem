#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    int answer = -1;
    for(int i = 0; i < A.size(); i++) {
        A = A + A[0];
        A.erase(A.begin());
        if(A.compare(B) == 0) {
            answer = A.size() - i - 1;
            break;
        }
    }
    return answer;
}