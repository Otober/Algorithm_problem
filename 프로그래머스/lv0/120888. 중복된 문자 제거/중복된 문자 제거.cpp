#include <string>
#include <vector>

using namespace std;

const int N = 26;

bool blank = false;

bool lower_visit[N] = {};
bool upper_visit[N] = {};


string solution(string my_string) {
    string answer = "";
    for(int i = 0; i < my_string.size(); i++) {
        if(my_string[i] == ' ') {
            if(blank == false) {
                answer += " ";
                blank = true;
            }
        }
        else if(my_string[i] >= 'a' && my_string[i] <= 'z') {
            if(lower_visit[my_string[i] - 'a'] == false) {
                lower_visit[my_string[i] - 'a'] = true;
                answer += my_string[i];
            }
        }
        else if(my_string[i] >= 'A' && my_string[i] <= 'Z') {
            if(upper_visit[my_string[i] - 'A'] == false) {
                upper_visit[my_string[i] - 'A'] = true;
                answer += my_string[i];
            }
        }
    }
    return answer;
}