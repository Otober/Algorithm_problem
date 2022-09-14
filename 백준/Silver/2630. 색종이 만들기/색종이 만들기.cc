#include <iostream>
#define N 130

using namespace std;

int white = 0;
int blue = 0;
bool arr[N][N] = {};

void recursive(int di, int dj, int size) {
    bool temp = arr[di][dj];
    bool flag = false;
    for(int i = di; i < di + size; i++) {
        if(flag) break;
        for(int j = dj; j < dj + size; j++) {
            if(temp != arr[i][j]) {
                flag = true;
                break;
            }
        }
    }
    
    if(flag == true) {
        recursive(di, dj, size / 2);
        recursive(di + size / 2, dj, size / 2);
        recursive(di, dj + size / 2, size / 2);
        recursive(di + size / 2, dj + size / 2, size / 2);
    }
    else {
        if(temp) blue++;
        else white++;
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    recursive(0, 0, n);
    cout << white << endl;
    cout << blue << endl;
}