#include <iostream>
#include <vector>
#define N 360000

using namespace std;

int n;

bool s[2 * N] = {};
bool p[N] = {};
bool flag = false;

vector < int > pi(N, 0);

void f_getpi() {
    int j = 0;
    for(int i = 1; i < N; i++) {
        while(j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if(p[i] == p[j]) pi[i] = ++j;
    }
}

void f_kmp() {
    int j = 0;
    f_getpi();
    for(int i = 0; i < 2 * N; i++) {
        while(j > 0 && s[i] != p[j]) {
            j = pi[j - 1];
        }
        if(s[i] == p[j]) {
            if(j == N - 1) {
                flag = true;
                return;
            }
            else j++;
        }
    }
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        s[num] = true;
        s[num + N] = true;
    }
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        p[num] = true;
    }
    f_kmp();
    if(flag) cout << "possible";
    else cout << "impossible";
    return 0;
}