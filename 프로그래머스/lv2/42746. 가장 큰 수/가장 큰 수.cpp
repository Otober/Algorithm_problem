#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string &a, string &b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector <string> temp;
    for(int num : numbers) {
        temp.push_back(to_string(num));
    }
    sort(temp.begin(), temp.end(), cmp);
    if(temp[0] == "0") answer += "0";
    else {
        for(string str : temp) {
            answer += str;
        }
    }
    return answer;
}