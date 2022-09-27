#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const long long INT_MAX = 20000000000;

vector < pair < long long, long long > > v;

void f_intersection(vector < int > a, vector < int > b) {
    long long temp = (1LL * a[0] * b[1] - a[1] * b[0]);
    if(temp != 0) {
        long long tx = (1LL * a[1] * b[2] - a[2] * b[1]);
        long long ty = (1LL * a[2] * b[0] - a[0] * b[2]);
        
        if(tx % temp == 0 && ty % temp == 0) {
            v.push_back(make_pair(tx/temp, ty/temp));
        }
    }
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;

    for (int i = 0; i < line.size(); i++) {
        for (int j = i + 1; j < line.size(); j++) {
            f_intersection(line[i], line[j]);
        }
    }
    long long x_min = INT_MAX, y_min = INT_MAX;
    long long x_max = -INT_MAX, y_max = -INT_MAX;

    for (int i = 0; i < v.size(); i++) {
        if (x_min > v[i].first) x_min = v[i].first;
        if (x_max < v[i].first) x_max = v[i].first;
        if (y_min > v[i].second) y_min = v[i].second;
        if (y_max < v[i].second) y_max = v[i].second;
    }
    string str(x_max - x_min + 1, '.');
    answer.assign(y_max - y_min + 1, str);
    for(int i = 0; i < v.size(); i++) {
        answer[y_max - v[i].second][v[i].first - x_min] = '*';
    }
    return answer;
}