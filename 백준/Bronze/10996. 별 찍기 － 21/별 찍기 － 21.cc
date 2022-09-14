#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= 2*n; i++) {
        if(i % 2 == 1) {
            for(int j = 1; j <= n; j++) {
                if(j % 2 == 1) cout << "*";
                else cout << " ";
            }
        }
        else {
            for(int j = 1; j <= n; j++) {
                if(j % 2 == 0) cout << "*";
                else cout << " ";
            }
        }
        cout << endl;
    }
}
