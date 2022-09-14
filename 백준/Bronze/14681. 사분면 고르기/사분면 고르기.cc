#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if(n > 0 && m > 0) cout <<"1" <<endl;
    if(n < 0 && m > 0) cout <<"2" <<endl;
    if(n < 0 && m < 0) cout <<"3" <<endl;
    if(n > 0 && m < 0) cout <<"4" <<endl;
    return 0;
}