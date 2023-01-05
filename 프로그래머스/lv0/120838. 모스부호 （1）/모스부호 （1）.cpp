#include <string>
#include <vector>

using namespace std;

vector < string > morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

string solution(string letter) {
    string answer = "";
    letter += ' ';
    int index = 0;
    for(int i = 0; i < letter.size(); i++) {
        if(letter[i] == ' ') {
            string temp = letter.substr(index, i - index);
            for(int j = 0; j < morse.size(); j++) {
                if(morse[j] == temp) {
                    answer.push_back('a' + j);
                    break;
                }
            }
            index = i + 1;
        }
    }
    return answer;
}