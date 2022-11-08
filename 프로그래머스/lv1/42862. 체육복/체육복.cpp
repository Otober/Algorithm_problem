#include <string>
#include <vector>

using namespace std;

const int NMAX = 35;

int check[NMAX] = {};

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for(int i = 0; i < lost.size(); i++) {
        check[lost[i]]--;
    }
    for(int i = 0; i < reserve.size(); i++) {
        check[reserve[i]]++;
    }
    
    for(int i = 1; i <= n; i++) {
        if(check[i] == -1 && check[i - 1] == 1) {
            check[i]++;
            check[i -1]--;
        }
        if(check[i] == -1 && check[i + 1] == 1) {
            check[i]++;
            check[i + 1]--;
        }
        if(check[i] == 0 || check[i] == 1) answer++;
    }
    return answer;
}