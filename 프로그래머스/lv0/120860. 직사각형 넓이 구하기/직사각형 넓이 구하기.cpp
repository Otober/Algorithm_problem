#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    int side1, side2;
    for(int i = 1; i < dots.size(); i++) {
        if(dots[0][0] == dots[i][0]) side1 = abs(dots[0][1] - dots[i][1]);
        else if(dots[0][1] == dots[i][1]) side2 = abs(dots[0][0] - dots[i][0]);
    }
    return answer = side1 * side2;
}