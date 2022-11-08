#include <string>
#include <vector>

using namespace std;

pair < int, int > f_position(int node) {
    if(node == 0) return {3, 1};
    else if(node == -1) return {3, 0};
    else if(node == -2) return {3, 2};
    else return {(node - 1) / 3, (node - 1) % 3};
}

int f_dist(int now, int next) {
    pair < int, int > first = f_position(now);
    pair < int, int > second = f_position(next);
    return abs(second.first - first.first) + abs(second.second - first.second);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = -1;
    int right = -2;
    for(int i = 0; i < numbers.size(); i++) {
        int node = numbers[i];
        if(node == 1 || node == 4 || node == 7) {
            left = node;
            answer += "L";
        }
        else if(node == 3 || node == 6 || node == 9) {
            right = node;
            answer += "R";
        }
        else {
            int ldist = f_dist(left, node);
            int rdist = f_dist(right, node);
            if(ldist < rdist) {
                left = node;
                answer += "L";
            }
            else if(ldist > rdist) {
                right = node;
                answer += "R";
            }
            else {
                if(hand == "right") {
                    right = node;
                    answer += "R";
                }
                else {
                    left = node;
                    answer += "L";
                }
            }
        }
    }
    return answer;
}