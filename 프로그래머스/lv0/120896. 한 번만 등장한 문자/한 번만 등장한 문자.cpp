#include <string>
#include <vector>

using namespace std;

const int N = 26;

int alphabets[N] = {};

string solution(string s) {
    string answer = "";
    for(int i = 0; i < s.size(); i++) {
        alphabets[(int)s[i] - 'a']++;
    }
    for(int i = 0; i < N; i++) {
        if(alphabets[i] == 1) answer+= i + 'a';
    }
    return answer;
}