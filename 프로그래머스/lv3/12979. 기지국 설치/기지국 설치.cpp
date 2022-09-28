#include <iostream>
#include <vector>

using namespace std;

vector < int > v;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int last = stations[0] - w;
    if(last > 1) v.push_back(last - 1);
    last = stations[0] + w + 1;
    for(int i = 1; i < stations.size(); i++) {
        int temp = stations[i]- w - last;
        if(temp > 0)v.push_back(temp);
        last = stations[i] + w + 1;
    }
    if(n - last + 1> 0) v.push_back(n - last + 1);
    for(int i = 0; i < v.size(); i++) {
        answer += v[i] / (2 * w + 1);
        if(v[i] % (2 * w + 1) != 0) answer += 1;
    }
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return answer;
}