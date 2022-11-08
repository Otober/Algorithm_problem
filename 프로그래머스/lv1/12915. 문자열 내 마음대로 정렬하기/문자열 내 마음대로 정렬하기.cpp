#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int condition;

bool cmp(string &a, string &b) {
    if(a[condition] == b[condition]) return a < b;
    return a[condition] < b[condition];
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    condition = n;
    sort(strings.begin(), strings.end(), cmp);
    return answer = strings;
}