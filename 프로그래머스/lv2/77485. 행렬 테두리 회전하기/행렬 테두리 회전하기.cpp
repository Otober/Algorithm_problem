#include <string>
#include <vector>

#include <iostream>

using namespace std;

const int N = 105;

int matrix[N][N] = {};

void f_initialize(int rows, int columns) {
    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= columns; j++) {
            matrix[i][j] = (i - 1) * columns + j;
        }
    }
     for(int i = 1; i <= rows; i++) {
            for(int j = 1; j <= columns; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    f_initialize(rows, columns);
    for(int i = 0; i < queries.size(); i++) {
        int sy = queries[i][0];
        int sx = queries[i][1];
        int ey = queries[i][2];
        int ex = queries[i][3];
        int temp = matrix[sy][sx];
        int tmin = temp;
            
        for(int i = sy; i < ey; i++) {
            matrix[i][sx] = matrix[i + 1][sx];
            if(tmin > matrix[i][sx]) tmin = matrix[i][sx];
        }
        for(int i = sx; i < ex; i++) {
            matrix[ey][i] = matrix[ey][i + 1];
            if(tmin > matrix[ey][i]) tmin = matrix[ey][i]; 
        }
        for(int i = ey; i > sy; i--) {
            matrix[i][ex] = matrix[i - 1][ex];
            if(tmin > matrix[i][ex]) tmin = matrix[i][ex];
        }
        for(int i = ex; i > sx; i--) {
            matrix[sy][i] = matrix[sy][i - 1];
            if(tmin > matrix[sy][i]) tmin = matrix[sy][i];
        }
        matrix[sy][sx + 1] = temp;
        answer.push_back(tmin);
       
    }
    return answer;
}