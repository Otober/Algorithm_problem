#include <iostream>
#define N 105
#define INF 987654321

using namespace std;

int n;
int max_ans = -INF;
int min_ans = INF;
int sign_cnt = 0;
int arr[N] = {};
int sign[4] = {};

int f_min(int &a, int &b) {
    return a < b ? a : b;
}

int f_max(int &a, int &b) {
    return a > b ? a : b;
}

void f_calculate(int cnt, int sum) {
    if(n == cnt) {
        min_ans = f_min(min_ans, sum);
        max_ans = f_max(max_ans, sum);
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        if(sign[i] - 1 >= 0) {
            sign[i]--;
            if(i == 0) f_calculate(cnt + 1, sum + arr[cnt]);
            else if(i == 1) f_calculate(cnt + 1, sum - arr[cnt]);
            else if(i == 2) f_calculate(cnt + 1, sum * arr[cnt]);
            else if(i == 3) f_calculate(cnt + 1, sum / arr[cnt]);
            sign[i]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < 4; i++) {
        cin >> sign[i];
        sign_cnt += sign[i];
    }
    f_calculate(1, arr[0]);
    cout << max_ans << endl;
    cout << min_ans << endl;
    return 0;
}