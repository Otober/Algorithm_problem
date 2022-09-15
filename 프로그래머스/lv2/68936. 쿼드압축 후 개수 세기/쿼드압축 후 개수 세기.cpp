#include <string>
#include <vector>

using namespace std;

const int N = 1100;


int cnt[2] = {};

void f_merge(int y, int x, int size, vector<int>& answer, vector<vector< int > >& arr) {
    bool one = true, zero = true;
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (arr[i][j] == 0) one = false;
            else zero = false;
        }
    }
    if (zero) {
        answer[0]++;
        return;
    }
    if (one) {
        answer[1]++;
        return;
    }
    f_merge(y, x, size / 2, answer, arr);
    f_merge(y + size / 2, x, size / 2, answer, arr);
    f_merge(y, x + size / 2, size / 2, answer, arr);
    f_merge(y + size / 2, x + size / 2, size / 2, answer, arr);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2);
    f_merge(0, 0, arr.size(), answer, arr);
    return answer;
}