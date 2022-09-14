#include <iostream>
#define N 1005

using namespace std;

int dy[N] = {};
int arr[N];

int main() {
    int n;
    int max = 0;
    cin >> n;
    for(int i = 1 ; i <= n ; i++ ) {
        cin >> arr[i];
    }
    for(int i = 1 ; i <= n ; i++ ) {
        int temp = 0;
        for(int j = 0 ; j < i ; j++ ) {
            if(arr[j] < arr[i]) {
                if(temp < dy[j]) temp = dy[j];
            }
        }
        dy[i]=temp + 1;
        if(max < dy[i]) max = dy[i];
    }
    cout << max << endl;
    return 0;
}