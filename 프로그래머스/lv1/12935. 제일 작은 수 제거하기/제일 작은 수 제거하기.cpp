#include <string>
#include <vector>

using namespace std;

const int INT_MAX = 987654321;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int idx = -1;
    int temp = INT_MAX;
    for(int i = 0; i < arr.size(); i++) {
        if(temp > arr[i]) {
            temp = arr[i];
            idx = i;
        }
    }
    arr.erase(arr.begin() + idx);
    if(arr.empty()) answer.push_back(-1);
    else answer = arr;
    return answer;
}