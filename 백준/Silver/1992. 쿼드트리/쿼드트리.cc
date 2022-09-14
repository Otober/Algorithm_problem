#include <iostream>
#include <cstdio>
#define N 70

using namespace std;

int n;
bool arr[N][N] = {};

void recursive(int di, int dj, int size) {
    bool flag = false;
    bool temp = arr[di][dj];
    
    if(size == 1) {
        cout << temp;
        return;
    }
    
    for(int i = di; i < di + size; i++) {
        if(flag) break;
        for(int j = dj; j < dj + size; j++) {
            if(temp != arr[i][j]) {
                flag = true;
                break;
            }
        }
    }
    
    if(flag) {
        cout << "(";
        recursive(di, dj, size / 2);
        recursive(di, dj + size / 2, size / 2);
        recursive(di + size / 2, dj, size / 2);
        recursive(di + size / 2, dj + size / 2, size / 2);
        cout << ")";
    }
    else {
        cout << temp;
    }
    return ;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    recursive(0, 0, n);
    return 0;
}