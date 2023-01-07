#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int tmax = -987654321;
    int tmin = 987654321;
    int j = 0;
    for(int i = 0; i <= s.size(); i++) {
        if(s[i] == ' ' || i == s.size()) {
            int n = stoi(s.substr(j, i - j));
            j = i + 1;
            if(tmax < n) tmax = n;
            if(tmin > n) tmin = n;
        }
    }
    answer = to_string(tmin) + ' ' + to_string(tmax);
    return answer;
}