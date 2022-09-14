#include <iostream>
#include <climits>

using namespace std;

int main() {
    int x,y,w,h;
    int temp = INT_MAX;
    cin >> x >> y >> w >> h;
    if(w - x < temp) temp = w - x;
    if(x < temp) temp = x;
    if(h - y < temp) temp = h - y;
    if(y < temp) temp = y;
    cout << temp << endl;
}