#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int n = t.size();
    int m = p.size();
    for(int i = 0; i <= n - m; i++) {
        string temp = t.substr(i, m);
        if(temp.compare(p) <= 0) answer++;
    }
    return answer;
}