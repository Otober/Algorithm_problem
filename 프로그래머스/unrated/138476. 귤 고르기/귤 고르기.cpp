#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map < int, int > m;
vector < pair < int, int > > v;

bool cmp(pair < int, int > &a, pair < int, int > &b) {
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    for(int i = 0; i < tangerine.size(); i++) {
        auto iter = m.find(tangerine[i]);
        if(iter == m.end()) m.insert(make_pair(tangerine[i], 1));
        else {
            iter->second++;
        }
    }
    v.resize(m.size());
    copy(m.begin(), m.end(), v.begin());
    sort(v.begin(), v.end(), cmp);
    
    int index = 0;
    while(k > 0) {
        answer++;
        k -= v[index].second;
        index++;
    }
    return answer;
}