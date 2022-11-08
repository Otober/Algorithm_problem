#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int left = 1;
    int right = distance;
    sort(rocks.begin(), rocks.end());
    while(left <= right) {
        int mid = (left + right ) / 2;
        int cnt = 0;
        int idx = -1;
        for(int i = 0; i <= rocks.size(); i++) {
            int d;
            if(idx == -1) d = rocks[i];
            else if(i == rocks.size()) d = distance - rocks.back();
            else d = rocks[i] - rocks[idx];
            
            if(d < mid) cnt++;
            else idx = i;
        }
        if(cnt > n) right = mid - 1;
        else if(cnt <= n) {
            left = mid + 1;
            answer = max(answer, mid);
        }
    }
    return answer;
}