#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector < int > v(1005);

int solution(vector<int> array) {
    int answer = 0;
    for(int i = 0; i < array.size(); i++) {
        v[array[i]]++;
    }
    auto iter1 = max_element(v.begin(), v.end());
    auto iter2 = max_element(iter1 + 1, v.end());
    if(*iter1 == *iter2) answer = -1;
    else answer = iter1 - v.begin();
    return answer;
}