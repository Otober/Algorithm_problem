#include <iostream>

using namespace std;

int solution(int k, int n) {
    if(n == 1) return 1;
    if(k == 0) return n;
    return solution(k - 1, n) + solution(k, n - 1);
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int k, n;
        cin >> k >> n;
        cout << solution(k,n) << endl;
    }
}