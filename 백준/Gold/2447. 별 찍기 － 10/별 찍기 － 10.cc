#include <iostream>
#define N 2200

using namespace std;

bool map[N][N] = {};

void setstar(int y, int x, int size) {
    //need recursive stop condition
    if(size == 1) {
        map[y][x] = true;
        return;
    }
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == 1 && j == 1) continue;
            setstar(y + i * (size / 3),x + j * (size /3), size/3);
        }
    }
    
}

void draw(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i][j] == true) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    setstar(0, 0, n);
    draw(n);
    return 0;
}