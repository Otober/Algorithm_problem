#include <string>
#include <vector>

using namespace std;

const int N_MAX = 10000000;
const int N = 10;

int cnt = 0;

bool visit[N_MAX] = {};
bool chk[N] = {};

bool check_prime(int n) {
    if(n == 0) return false;
    if(n == 1) return false;
    if(n == 2) return true;
    for(int i = 2; i <= n / 2; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

void reculsive_function(string st, int n, string numbers) {
    int temp = atoi(st.c_str());
    if(visit[temp] == false) {
        visit[temp] = true;
        if(check_prime(temp)) {
            cnt++;
            visit[temp] = true;
        }
    }
    for(int i = 0; i < n; i++) {
        if(chk[i] == false) {
            chk[i] = true;
            reculsive_function(st + numbers[i], n, numbers);
            chk[i] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    for(int i = 0; i < numbers.size(); i++) {
        chk[i] = true;
        reculsive_function(numbers.substr(i,1), numbers.size(), numbers);
        chk[i] = false;
    }
    return answer = cnt;
}