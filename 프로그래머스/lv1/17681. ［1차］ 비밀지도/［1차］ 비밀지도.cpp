#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i < n; i++) {
        string st = "";
        int temp = arr1[i] | arr2[i];
        for(int j = 0; j < n; j++) {
            if(temp & (1 << j)) st += "#";
            else st += " ";
        }
        reverse(st.begin(), st.end());
        answer.push_back(st);
    }
    return answer;
}