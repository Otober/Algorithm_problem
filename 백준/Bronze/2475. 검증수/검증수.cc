#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int answer = 0;
    for(int i = 0; i < 5; i++) {
        int temp;
        cin >> temp;
        temp = temp * temp;
        answer += temp % 10;
    }
    cout << answer % 10;
    return 0;
}