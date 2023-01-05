#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    vector < int > temp;
    for(int i = 0; i < num_list.size(); i++) {
        temp.push_back(num_list[i]);
        if(temp.size() == n) {
            answer.push_back(temp);
            temp.clear();
        }
    }
    return answer;
}