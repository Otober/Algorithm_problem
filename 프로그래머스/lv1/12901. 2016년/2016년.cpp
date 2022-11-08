#include <string>
#include <vector>

using namespace std;

const int mday[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string week[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};

string solution(int a, int b) {
    string answer = "";
    int day = 0;
    for(int i = 1; i < a; i++) {
        day += mday[i];
    }
    day += b - 1;
    answer = week[day % 7];
    return answer;
}