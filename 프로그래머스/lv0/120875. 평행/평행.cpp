#include <string>
#include <vector>

using namespace std;

int d[3][4] ={
    {0, 1, 2, 3},
    {0, 2, 1, 3},
    {0, 3, 1, 2}
};

int solution(vector<vector<int>> dots) {    
    int answer = 0;
    for(int i = 0; i < 3; i++) {
        int t_y_1 = dots[d[i][0]][0] - dots[d[i][1]][0];
        int t_x_1 = dots[d[i][0]][1] - dots[d[i][1]][1];
        int t_y_2 = dots[d[i][2]][0] - dots[d[i][3]][0];
        int t_x_2 = dots[d[i][2]][1] - dots[d[i][3]][1];
        double t_1 = (double)t_x_1 / t_y_1;
        double t_2 = (double)t_x_2 / t_y_2;
        if(t_1 == t_2) {
            answer = 1;
            break;
        }
    }
    return answer;
}