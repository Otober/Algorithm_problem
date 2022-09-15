#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool binary_search(vector < int > stones, int mid, int k) {
    int cnt = 0;
    for(int i = 0; i < stones.size(); i++) {
        if(stones[i] - mid <= 0) cnt++;
        else cnt = 0;
        if(cnt >=k) return true;
    }
    return false;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int tmin = *min_element(stones.begin(), stones.end());
    int tmax = *max_element(stones.begin(), stones.end());
    
    while(tmin <= tmax) {
        int mid = (tmin + tmax) / 2;
        if(binary_search(stones, mid, k)) tmax = mid - 1;
        else tmin = mid + 1;
    }
    return answer = tmin;
}