#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    int mid = -1;
    for(int i = 0; i < food.size(); i++) {
        if(mid == -1 && food[i] == 1) {
            mid = i;
        }
        else {
            for(int j = 0; j < food[i] / 2; j++) {
                answer += '0' + i;
            }
        }
    }
    string temp = answer;
    reverse(temp.begin(), temp.end());
    answer += '0' + mid;
    answer += temp;
    return answer;
}