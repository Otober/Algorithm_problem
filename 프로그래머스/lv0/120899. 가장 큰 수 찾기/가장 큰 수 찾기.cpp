#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    int t_max = -987654321;
    int index = -1;
    for(int i = 0; i < array.size(); i++) {
        if(t_max < array[i]) {
            index = i;
            t_max = array[i];
        }
    }
    answer.push_back(t_max);
    answer.push_back(index);
    return answer;
}