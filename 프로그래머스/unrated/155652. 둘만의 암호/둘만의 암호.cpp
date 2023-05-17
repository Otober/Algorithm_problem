#include <string>
#include <vector>

using namespace std;

const int alphabets = 26;

bool visit[alphabets] = {};

string solution(string s, string skip, int index) {
    string answer = "";
    for(int i = 0; i < skip.size(); i++) {
        visit[skip[i] - 'a'] = true;
    }
    for(int i = 0; i < s.size(); i++) {
        int temp = (s[i] - 'a') % alphabets;
        for(int j = 1; j <= index; j++) {
            temp = (temp + 1) % alphabets;
            if(visit[temp]) j--;
        }
        s[i] = temp + 'a';
    }
    return answer = s;
}