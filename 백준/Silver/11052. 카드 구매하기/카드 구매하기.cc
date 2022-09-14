#include <iostream>
#define N 1005

using namespace std;

int dy[N] = {};
int card[N] = {};

int main() {
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++) {
        cin >> card[i];
    }
    
    for(int i = 1 ; i <= n ; i++) {
        int temp = 0;
        for(int j=1 ; j <= i ; j++) {
            if(temp < card[j] + dy[i-j]) temp = card[j] + dy[i-j];
        }
        dy[i] = temp;
    }
    
    cout << dy[n] << endl;
    return 0;
}