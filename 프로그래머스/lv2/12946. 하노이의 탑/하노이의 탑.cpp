#include <string>
#include <vector>

using namespace std;

void f_hannoi(int n, int from, int by, int to, vector < vector < int > > &answer) {
    if(n == 1) {
        answer.push_back({from, to});
    }
    else {
        f_hannoi(n - 1, from, to, by, answer);
        answer.push_back({from, to});
        f_hannoi(n - 1, by, from, to, answer);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    f_hannoi(n, 1, 2, 3, answer);
    return answer;
}