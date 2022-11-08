#include <string>
#include <vector>

using namespace std;

int f_gcd(int a, int b) {
    while(b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    int gcd = f_gcd(n, m);
    answer.push_back(gcd);
    answer.push_back(n * m / gcd);
    return answer;
}