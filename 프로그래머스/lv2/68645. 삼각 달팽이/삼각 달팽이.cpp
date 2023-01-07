#include <string>
#include <vector>

using namespace std;

const int N = 1005;

int arr[N][N] = {};
int y = 0, x = 0;
int cnt = 1;

void f_down(int n) {
    int tcnt = 0;
    while(tcnt <= n) {
        arr[y][x] = cnt++;
        tcnt++;
        if(arr[y + 1][x] == 0 && y + 1 < n) y++;
        else break;
    }
    return;
}

void f_right(int n) {
    int tcnt = 0;
    while(tcnt <= n) {
        arr[y][x] = cnt++;
        tcnt++;
        if(arr[y][x + 1] == 0 && x + 1 < n) x++;
        else break;
    }
    return;
}

void f_diagonal() {
    while(true) {
        arr[y][x] = cnt++;
        if(arr[y - 1][x - 1] == 0) {
            x--;
            y--;
        }
        else break;
    }
    return;
}

vector<int> solution(int n) {
    vector<int> answer;
    const int Max = (n * (n + 1)) / 2;
    while(true) {
        f_down(n);
        x++;
        if(cnt > Max) break;
        f_right(n);
        x--;
        y--;
        if(cnt > Max) break;
        f_diagonal();
        y++;
        if(cnt > Max) break;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            answer.push_back(arr[i][j]);
        }
    }
    return answer;
}