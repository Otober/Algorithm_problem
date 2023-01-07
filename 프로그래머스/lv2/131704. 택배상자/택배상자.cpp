#include <string>
#include <vector>
#include <stack>

using namespace std;

stack < int > st;

int solution(vector<int> order) {
    int answer = 0;
    for(int i = 1; i <= order.size(); i++) {
        st.push(i);
        while(!st.empty()) {
            if(st.top() == order[answer]) {
                answer++;
                st.pop();
            }
            else break;
        }
    }
    return answer;
}