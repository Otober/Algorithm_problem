#include <iostream>
#define N 1500005
#define devive 1000000

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    int arr[N] = {};
    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2; i <= N; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % devive;
    }
    cin >> n;
    cout << arr[n % 1500000];
    return 0;
}