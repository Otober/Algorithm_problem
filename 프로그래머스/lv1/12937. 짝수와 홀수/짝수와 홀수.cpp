#include <string>
#include <vector>

using namespace std;

const string number[2] = {"Even", "Odd"};

string solution(int num) {
    string answer = "";
    if(num < 0) num = -num;
    return answer = number[num % 2];
}