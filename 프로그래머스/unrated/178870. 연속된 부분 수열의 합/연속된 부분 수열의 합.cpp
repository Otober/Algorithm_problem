#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int left = sequence.size() - 1;
    int right = sequence.size() - 1;
    int sum = sequence[left];
    while(sum != k) {
        if(sum < k) {
            left--;
            sum += sequence[left];
        }
        else if(sum > k) {
            sum -= sequence[right];
            right--;
        }
    }
    while(left > 0) {
        sum -= sequence[right];
        sum += sequence[left - 1];
        if(sum == k) {
            left--;
            right--;
        }
        else break;
    }
    answer.push_back(left);
    answer.push_back(right);
    return answer;
}