#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = n * (long long)times.back();
    long long min = 1;
    long long max = n * (long long)times.back();
    long long sum;
    while(min <= max) {
        sum = 0;
        long long mid = (min + max) / 2;
        for(int i = 0; i < times.size(); i++) {
            sum += mid / times[i];
        }
        if(sum < n) min = mid + 1;
        else {
            if(mid < answer) answer = mid;
            max = mid - 1;
        }
    }
    return answer;
}