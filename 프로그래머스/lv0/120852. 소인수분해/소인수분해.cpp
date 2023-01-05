#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int temp = 2;
    bool flag = false;
    while(temp <= n) {
        if(n % temp == 0) {
            flag = true;
            n /= temp;
        }
        else {
            if(flag) {
                answer.push_back(temp);
                flag = false;
            }
            temp++;
        }
    }
    if(flag) answer.push_back(temp);
    return answer;
}