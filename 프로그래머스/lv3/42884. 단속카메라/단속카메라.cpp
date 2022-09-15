#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int end = -40000;
    sort(routes.begin(), routes.end());
    
    for(int i = 0; i < routes.size(); i++) {
        if(routes[i][1] < end) end = routes[i][1];
        if(routes[i][0] > end) {
            answer++;
            end = routes[i][1];
        }
    }
    return answer;
}