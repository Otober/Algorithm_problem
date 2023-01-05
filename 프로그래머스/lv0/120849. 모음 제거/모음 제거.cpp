#include <string>
#include <vector>

using namespace std;

char vowel[] = {'a', 'e', 'i', 'o', 'u'};

bool f_check(char c) {
    for(int i = 0; i < 5; i++) {
        if(c == vowel[i]) return false;
    }
    return true;
}

string solution(string my_string) {
    string answer = "";
    for(int i = 0; i < my_string.size(); i++) {
        if(f_check(my_string[i])) answer.push_back(my_string[i]);
    }
    return answer;
}