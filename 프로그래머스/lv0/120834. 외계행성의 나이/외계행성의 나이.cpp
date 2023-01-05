#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = "";
    while(age > 0) {
        char temp = (age % 10) + 'a';
        answer = temp + answer;
        age /= 10;
    }
    return answer;
}