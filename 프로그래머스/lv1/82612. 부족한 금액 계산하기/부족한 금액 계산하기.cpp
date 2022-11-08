using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    long long m = money;
    for(int i = 1; i <= count; i++) {
        m -= (long long)price * i;
    }
    if(m < 0) answer = -m;
    return answer;
}