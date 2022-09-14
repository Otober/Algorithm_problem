#include <iostream>
#include <algorithm>
#include <string>
#define N 100005

using namespace std;

struct Register {
    int age;
    int number;
    string name;
} re[N];

bool cmp(Register &a, Register &b) {
    if(a.age < b.age) return true;
    else if(a.age == b.age) {
        if(a.number < b.number) return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> re[i].age >> re[i].name;
        re[i].number = i;
    }
    
    sort(re, re + n, cmp);
    for(int i = 0; i < n; i++) {
        cout << re[i].age << " " << re[i].name << "\n";
    }
    return 0;
}