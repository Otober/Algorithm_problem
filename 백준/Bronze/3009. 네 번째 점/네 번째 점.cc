#include <iostream>
#define N 3

using namespace std;

int main() {
    int x[N],y[N];
    for(int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    if(x[0] == x[1]) cout << x[2]<< " ";
    else if(x[1] == x[2]) cout << x[0] << " ";
    else cout << x[1] << " ";
    
    if(y[0] == y[1]) cout << y[2]<< " ";
    else if(y[1] == y[2]) cout << y[0] << " ";
    else cout << y[1] << " ";
}