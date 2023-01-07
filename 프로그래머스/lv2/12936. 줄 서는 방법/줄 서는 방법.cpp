#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector < int > v;
    long long factorial = 1;
    
    for(int i = 1; i <= n; i++) {
        v.push_back(i);
        factorial *= i;
    }
    while(n) {
        factorial /= n;
        long long num = !k ? n - 1 : (k - 1) / factorial;
        answer.push_back(v[num]);
        v.erase(v.begin() + num);
        k %= factorial;
        n--;
    }
    return answer;
}