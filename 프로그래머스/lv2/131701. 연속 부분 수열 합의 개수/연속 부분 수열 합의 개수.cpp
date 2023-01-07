#include <string>
#include <vector>
#include <set>

using namespace std;

set < int > s;

int solution(vector<int> elements) {
    int answer = 0;
    int n = elements.size();
    for(int i = 0; i < n; i++) {
        elements.push_back(elements[i]);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < elements.size() - i; j++) {
            int sum = 0;
            for(int k = 0; k <= i; k++) {
                sum += elements[j + k];
            }
            s.insert(sum);
        }
    }
    return answer = s.size();
}