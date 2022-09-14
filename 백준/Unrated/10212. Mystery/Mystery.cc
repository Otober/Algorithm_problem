#include <iostream>

using namespace std;

const int N = 1005;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long *temp = new long long;
    cout << ((long long)temp % 3 ? "Yonsei" : "Korea");
    return 0;
}