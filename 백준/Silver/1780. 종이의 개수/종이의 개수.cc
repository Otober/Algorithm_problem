#include <iostream>
#define N 2200

using namespace std;

int n;
int arr[N][N] = {};

int cnt_one = 0;
int cnt_zero = 0;
int cnt_minus_one = 0;

void recursive(int dy, int dx, int size) {
    int temp = arr[dy][dx];
    bool flag = false;
    
    for(int i = dy; i < dy + size; i++) {
        if(flag) break;
        for(int j = dx; j < dx + size; j++) {
            if(temp != arr[i][j]) {
                flag = true;
                break;
            }
        }
    }
    
    if(flag) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                recursive(dy + (size / 3) * i, dx + (size / 3) * j, size / 3);
            }
        }
    }
    else {
        if(temp == 1) cnt_one++;
        else if(temp == 0) cnt_zero++;
        else if(temp == -1) cnt_minus_one++;
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    recursive(0, 0, n);
    cout << cnt_minus_one << endl;
    cout << cnt_zero << endl;
    cout << cnt_one << endl;
    return 0;
}
