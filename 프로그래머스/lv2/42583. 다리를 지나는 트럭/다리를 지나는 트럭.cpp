#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int index = 0;
    int sum = 0;
    queue < pair < int, int > > q;
    
    while(true) {
        answer++;
        if(index < truck_weights.size() && sum + truck_weights[index] <= weight) {
            q.push(make_pair(truck_weights[index], answer));
            sum += truck_weights[index];
            index++;
        }
        int now = q.front().second;
        if(answer - now + 1 >= bridge_length) {
            sum -= q.front().first;
            q.pop();
        }
        if(index >= truck_weights.size() && q.empty()) break;
    }
    return answer + 1;
}