#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int g_col;

bool cmp(vector < int > &a, vector < int > &b) {
    if(a[g_col] == b[g_col]) {
        if(a[0] > b[0]) return true;
        else return false;
    }
    if(a[g_col] < b[g_col]) return true;
    else return false;
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    g_col = col - 1;
    sort(data.begin(), data.end(), cmp);
    for(int i = row_begin - 1; i <= row_end - 1; i++) {
        int sum = 0;
        for(int j = 0; j < data[i].size(); j++) {
            sum += data[i][j] % (i + 1);
        }
        answer ^= sum;
    }
    return answer;
}