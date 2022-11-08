#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    int index = 0;
    while(index < my_str.size()) {
        answer.push_back(my_str.substr(index, n));
        index += n;
    }
    return answer;
}