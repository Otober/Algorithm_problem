#include <string>
#include <vector>
#include <queue>

using namespace std;

const int N = 1000005;

bool visit[N] = {};

int arr[3] = {};

queue < pair < int, int > > q;

int solution(int x, int y, int n) {
    int answer = -1;
    q.push(make_pair(x, 0));
    while(!q.empty()) {
        int num = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(num == y) {
            answer = cnt;
            break;
        }
        int arr[3] = {};
        arr[0] = num + n;
        arr[1] = num * 2;
        arr[2] = num * 3;
        for(int i = 0; i < 3; i++) {
            if(arr[i] <= y && visit[arr[i]] == false) {
                q.push(make_pair(arr[i], cnt + 1));
                visit[arr[i]] = true;
            }
        }
    }
    return answer;
}