#include <string>
#include <vector>

using namespace std;

const int N = 205;
const int INT_MAX = 987654321;

int arr[N][N] = {};

int solution(vector<vector<int>> matrix_sizes) {
    int answer = 0;
    int n = matrix_sizes.size();
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n - i; j++) {
            int temp = INT_MAX;
            for(int k = 0; k < i; k++) {
                int sum = arr[k][j] + arr[i - 1 - k][j + 1 + k] + (matrix_sizes[j][0] * matrix_sizes[k + j][1] * matrix_sizes[i+j][1]);
                if(temp > sum) temp = sum;
            }
            arr[i][j] = temp;
        }
    }
    answer = arr[n - 1][0];
    return answer;
}