#include <string>
#include <vector>

using namespace std;

int f_gcd(int a, int b) {
    if(b == 0) return a;
    else return f_gcd(b, a % b);
}

vector<int> solution(int denum1, int num1, int denum2, int num2) {
    vector<int> answer;
    int denum = denum1 * num2 +  denum2 * num1;
    int num = num1 * num2;
    int gcd = f_gcd(denum, num);
    answer.push_back(denum / gcd);
    answer.push_back(num / gcd);
    return answer;
}