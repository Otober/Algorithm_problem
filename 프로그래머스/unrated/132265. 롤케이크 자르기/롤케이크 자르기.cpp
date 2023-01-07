#include <string>
#include <vector>
#include <set>

using namespace std;

const int N = 10005;

int visit[N] = {};

set < int > s;

int solution(vector<int> topping) {
    int answer = 0;
    int cnt = 1;
    visit[topping[0]]++;
    for(int i = 1; i < topping.size(); i++) {
        visit[topping[i]]++;
        if(visit[topping[i]] == 1) cnt++;
    }
    for(int i = 0; i < topping.size(); i++) {
        s.insert(topping[i]);
        visit[topping[i]]--;
        if(visit[topping[i]] == 0) cnt--;
        if(s.size() == cnt) answer++;
    }
    return answer;
}