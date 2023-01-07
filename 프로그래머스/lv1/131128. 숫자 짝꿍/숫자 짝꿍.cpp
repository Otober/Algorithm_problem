#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    sort(X.begin(), X.end(), greater<>());
    sort(Y.begin(), Y.end(), greater<>());
    if(X.size() < Y.size()) {
        string temp = Y;
        Y = X;
        X = temp;
    }
    int i = 0, j = 0;
    while(i < X.size() && j < Y.size()) {
        if(X[i] == Y[j]) {
            answer += X[i];
            i++;
            j++;
        }
        else if(X[i] > Y[j]) {
            i++;
        }
        else if(X[i] < Y[j]) {
            j++;
        }
    }
    if(answer.size() == 0) answer = "-1";
    else if(answer[0] == '0') answer = "0";
    return answer;
}