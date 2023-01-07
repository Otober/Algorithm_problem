#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char temp;
    vector<int> v(2);
    for(int i = 0; i < s.size(); i++) {
        if(v[0] == 0) {
            temp = s[i];
            v[0]++;
        }
        else {
            if(s[i] == temp) v[0]++;
            else v[1]++;
            
            if(v[0] == v[1]) {
                answer++;
                v[0] = 0;
                v[1] = 0;
            }
        }
    }
    if(v[0] != 0 || v[1] != 0) answer++;
    return answer;
}