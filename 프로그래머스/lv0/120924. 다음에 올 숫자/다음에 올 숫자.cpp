#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    if(common.size() < 3) {
        answer = common[1] * 2 - common[0];
    }
    else {
        bool flag = true;
        int temp = common[1] - common[0];
        for(int i = 1; i < common.size(); i++) {
            if(common[i] != common[i - 1] + temp) break;
            if(i == common.size() - 1) {
                answer = common[common.size() - 1] + temp;
                flag = false;
            }
        }
        if(flag) {
            temp = common[1] / common[0];
        for(int i = 1; i < common.size(); i++) {
            if(common[i] != common[i - 1] * temp) break;
            if(i == common.size() - 1) answer = common[common.size() - 1] * temp;
        }
        }
    }
    return answer;
}