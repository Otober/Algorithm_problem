#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    for(int i = 0; i < array.size(); i++) {
        int n = array[i];
        while(n > 0) {
            int temp = n % 10;
            n /= 10;
            if(temp == 7) answer++;
        }
    }
    return answer;
}