#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int i = 0, j = 0;
    while(i < A.size() && j < B.size()) {
        if(A[i] < B[j]) {
            answer++;
            j++;
            i++;
        }
        else j++;
    }
    return answer;
}