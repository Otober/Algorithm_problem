#include <iostream>
#include <algorithm>
#define N 105

using namespace std;

int dp[N] = {};

struct wire {
    int a, b;
}arr[N];

bool cmp(wire &i, wire &j) {
    if(i.a < j.a) return true;
    else if(i.a == j.a) {
        if(i.b < j.b) return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int solution = 0;
    for(int i = 0; i < n; i++) {
        cin >>  arr[i].a >> arr[i].b;
    }
    
    sort(arr, arr + n, cmp);
    
    for(int i = 0; i < n; i++) {
        int temp_max = 0;
        for(int j = 0; j < i; j++) {
            if(arr[i].b > arr[j].b) {
                if(temp_max < dp[j]) temp_max = dp[j];
            }
        }
        dp[i] = temp_max + 1;
        if(dp[i] > solution) solution = dp[i];
    }
    cout << n - solution;
    return 0;
}