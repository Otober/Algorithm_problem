#include <string>
#include <vector>

using namespace std;

vector < int > v;
vector < double > area;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    v.push_back(k);
    while(k > 1) {
        if(k % 2 == 0) k /= 2;
        else k = 3 * k + 1;
        
        v.push_back(k);
    }
    area.push_back(0.0);
    for(int i = 0; i < v.size() - 1; i++) {
        area.push_back((v[i] + v[i + 1]) / 2.0); 
        area[i + 1] += area[i];
    }
    int size = area.size();
    for(int i = 0; i < ranges.size(); i++) {
        int right = area.size() - 1 + ranges[i][1];
        int left = ranges[i][0];
        if(right < left) answer.push_back(-1.0);
        else {
            answer.push_back(area[right] - area[left]);
        }
    }
    return answer;
}