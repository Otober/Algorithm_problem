#include <iostream>
#include <algorithm>
#include <cstring>
#define N 3

using namespace std;

int arr[N] = {};

string temp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    cin >> temp;
    
    for(int i = 0; i < temp.length(); i++) {
        cout << arr[temp[i] - 'A'] << " ";
    }
    return 0;
}