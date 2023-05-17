#include <string>
#include <vector>

using namespace std;

const int INF = 987654321;

pair < int, int > tmin, tmax;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    tmin.first = INF; tmin.second = INF;
    tmax.first = -INF; tmax.second = -INF;
    for(int i = 0; i < wallpaper.size(); i++) {
        for(int j = 0; j < wallpaper[i].size(); j++) {
            if(wallpaper[i][j] == '#') {
                if(tmin.first > i) tmin.first = i;
                if(tmin.second > j) tmin.second = j;
                if(tmax.first < i) tmax.first = i;
                if(tmax.second < j) tmax.second = j;
            }
        }
    }
    answer.push_back(tmin.first);
    answer.push_back(tmin.second);
    answer.push_back(tmax.first + 1);
    answer.push_back(tmax.second + 1);
    return answer;
}