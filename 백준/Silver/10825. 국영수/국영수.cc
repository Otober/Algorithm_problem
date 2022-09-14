#include <iostream>
#include <cstring>
#include <algorithm>
#define N 100005

using namespace std;

struct Student {
    string name;
    int ko, en, ma;
}arr[N];

bool f_cmp(Student &a, Student &b) {
    if(a.ko > b.ko) return true;
    else if(a.ko == b.ko) {
        if(a.en < b.en) return true;
        else if(a.en == b.en) {
            if(a.ma > b.ma) return true;
            else if (a.ma == b.ma) {
                if(a.name < b.name) return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i].name >> arr[i].ko >> arr[i].en >> arr[i].ma;
    }
    
    sort(arr, arr + n, f_cmp);
    
    for(int i = 0; i < n; i++) {
        cout << arr[i].name << "\n";
    }
    return 0;
}