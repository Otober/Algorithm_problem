#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int N = 10005;

struct Music {
    int index;
    int plays;
    string genres;
}arr[N];

map < string, int > mp;

bool cmp(const Music &a, const Music &b) {
    if(mp[a.genres] == mp[b.genres]) return a.plays > b.plays;
    return mp[a.genres] > mp[b.genres];
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int n = genres.size();
    int idx = 1;
    int cnt = 1;
    
    for(int i = 0; i < n; i++) {
        mp[genres[i]] += plays[i];
        arr[i].index = i;
        arr[i].genres = genres[i];
        arr[i].plays = plays[i];
    }
    
    sort(arr, arr + n, cmp);
    answer.push_back(arr[0].index);
    while(idx < n) {
        if(arr[idx].genres != arr[idx - 1].genres) cnt = 0;
        if(cnt < 2) {
            answer.push_back(arr[idx].index);
            cnt++;
        }
        idx++;
    }
    return answer;
}