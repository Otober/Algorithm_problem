#include <iostream>
#include <algorithm>
#define N 100005

using namespace std;

struct meeting {
    int s,e;
} arr[N];

bool cmp(meeting &i, meeting &j) {
    if(i.e < j.e) return true;
    if(i.e == j.e) {
        if(i.s < j.s) return true;
    }
    return false;
}

int main() {
    int n;
    int temp = -1;
    int cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i].s >> arr[i].e;
    }
    sort(arr, arr + n,cmp);
    for(int i = 0; i < n; i++) {
        if(temp <= arr[i].s) {
            temp = arr[i].e;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}