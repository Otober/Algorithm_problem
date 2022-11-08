#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = array[0];
    int t_abs = abs(array[0] - n);
    for(int i = 1; i < array.size(); i++) {
        int temp = abs(array[i] - n);
        if(t_abs > temp || (t_abs == temp && answer > array[i]) ) {
            answer = array[i];
            t_abs = temp;
        }
    }
    return answer;
}