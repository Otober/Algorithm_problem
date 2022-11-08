#include <string>
#include <vector>

using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";
    int size = bin1.size();
    if(size < bin2.size()) size = bin2.size();
    while(bin1.size() != size) {
        bin1.insert(0, "0");
    }
    while(bin2.size() != size) {
        bin2.insert(0, "0");
    }
    bool flag = false;
    for(int i = size - 1; i >= 0; i--) {
        int temp = 0;
        if(bin1[i] == '1') temp++;
        if(bin2[i] == '1') temp++;
        if(flag) temp++;
        
        if(temp >= 2) flag = true;
        else flag = false;
        if(temp % 2 == 1) answer.insert(0, "1");
        else answer.insert(0, "0");
    }
    if(flag) answer.insert(0, "1");
    return answer;
}