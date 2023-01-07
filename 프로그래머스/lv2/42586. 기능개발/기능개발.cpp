// 문제가 개편되었습니다. 이로 인해 함수 구성이나 테스트케이스가 변경되어, 과거의 코드는 동작하지 않을 수 있습니다.
// 새로운 함수 구성을 적용하려면 [코드 초기화] 버튼을 누르세요. 단, [코드 초기화] 버튼을 누르면 작성 중인 코드는 사라집니다.
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue < pair < int, int > > q;
    for(int i  = 0; i < progresses.size(); i++) {
        q.push(make_pair(progresses[i], i));
    }
    while(!q.empty()) {
        int cnt = 0;
        int n = q.size();
        for(int i = 0; i < n; i++) {
            int work = q.front().first;
            int index = q.front().second;
            q.pop();
            work += speeds[index];
            if(work >= 100 && i == 0) {
                i--;
                n--;
                cnt++;
            }
            else q.push(make_pair(work, index));
        }
        if(cnt != 0) answer.push_back(cnt);
    }
    return answer;
}