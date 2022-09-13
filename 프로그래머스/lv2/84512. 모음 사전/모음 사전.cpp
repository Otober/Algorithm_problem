#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 5;

char words[N] = { 'A', 'E', 'I', 'O', 'U' };

vector < string > v;

void f_dfs(string str) {
    if (str.size() > 5) return;
    v.push_back(str);
    for (int i = 0; i < N; i++) {
        f_dfs(str + words[i]);
    }
}

int solution(string word) {
    int answer = 0;
    for (int i = 0; i < N; i++) {
        string temp;
        temp.push_back(words[i]);
        f_dfs(temp);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        if(word == v[i]) {
            answer = i + 1;
            break;
        }
    }
    return answer;
}