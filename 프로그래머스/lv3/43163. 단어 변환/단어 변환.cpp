#include <string>
#include <vector>
#include <queue>

const int MAX = 100;
const int N = 2505;

using namespace std;

int visit[MAX] = {};
queue < pair < string, int > > pq;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    for(int i = 0; i < words.size(); i++) {
        visit[i] = N;
        
    }
    pq.push(make_pair(begin, 0));
    while(!pq.empty()) {
        string st = pq.front().first;
        int cnt = pq.front().second;
        pq.pop();
        if(st == target) {
            answer = cnt;
            break;
        }
        
        for(int i = 0; i < words.size(); i++) {
            if(cnt >= visit[i]) continue;
            int tcnt = 0;
            for(int j = 0; j < st.size(); j++) {
                if(st[j] != words[i][j]) tcnt++;
            }
            if(tcnt <= 1) {
                visit[i] = cnt + 1;
                pq.push(make_pair(words[i], cnt + 1));
            }
        }
    }
    return answer;
}