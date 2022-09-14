#include <iostream>

using namespace std;

long long int dynamic[101][11];

int main() {
    int n;
    long long int sum = 0;
    cin >> n;
    for(int i = 1 ; i < 10 ; i++ ) {
        dynamic[1][i] = 1;
    } 
    for(int i = 2;i <= n ; i++ ) {
        for(int j = 0 ; j < 10 ; j++ ) {
            switch (j) {
                case 0:
                    dynamic[i][j] = dynamic[i-1][1];
                    break;
                case 9:
                    dynamic[i][j] = dynamic[i-1][8];
                    break;
                default :
                    dynamic[i][j]=(dynamic[i-1][j-1]+dynamic[i-1][j+1])%1000000000;
                    break;
            }
        }
    }
    for(int i = 0 ; i < 10 ; i++) {
        sum+=dynamic[n][i];
    }
    cout << sum % 1000000000 << endl;
    return 0;
}