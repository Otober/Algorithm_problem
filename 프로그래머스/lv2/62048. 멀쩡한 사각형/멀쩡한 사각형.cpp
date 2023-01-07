using namespace std;

long long f_gcd(long long a, long long b) {
    while(b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long solution(int w,int h) {
    long long a = (long long )w;
    long long b = (long long )h;
    long long answer = a * b - a - b + f_gcd(a, b);
    return answer;
}