#include <iostream>
#include <climits>
#define N 15

using namespace std;

int arr[N] = {};
int calculate[4] = {};
int answer_min = INT_MAX;
int answer_max = INT_MIN;
int n;

void dfs(int cnt, int answer) {
    if(cnt == n) {
        if(answer_max < answer) answer_max = answer;
        if(answer_min > answer) answer_min = answer;
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        if(calculate[i]) {
            switch(i) {
                case 0: 
                answer += arr[cnt];
                calculate[i]--;
                dfs(cnt + 1, answer);
                calculate[i]++;
                answer -=arr[cnt];
                break;
                
                case 1:
                answer -= arr[cnt];
                calculate[i]--;
                dfs(cnt + 1, answer);
                calculate[i]++;;
                answer += arr[cnt];
                break;
                
                case 2:
                answer *= arr[cnt];
                calculate[i]--;
                dfs(cnt + 1, answer);
                calculate[i]++;
                answer /= arr[cnt];
                break;
                
                case 3:
                int temp = answer;
                answer /= arr[cnt];
                calculate[i]--;
                dfs(cnt + 1, answer);
                calculate[i]++;
                answer = temp;
                break;
            }
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < 4; i++) {
        cin >> calculate[i];
    }
    dfs(1, arr[0]);
    cout << answer_max << "\n" << answer_min;
    return 0;
}