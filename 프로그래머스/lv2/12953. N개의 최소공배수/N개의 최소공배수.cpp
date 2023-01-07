#include <string>
#include <vector>

using namespace std;

int f_gcd(int a, int b) {
    while(b > 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int solution(vector<int> arr) {
    int answer = 0;
    int temp = arr[0];
    for(int i = 1; i < arr.size(); i++) {
        temp = temp * arr[i] / f_gcd(temp, arr[i]);
    }
    return answer = temp;
}