#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector < string > cache;
    if(cacheSize == 0) return cities.size() * 5;
    
    for(int i = 0; i < cities.size(); i++) {
        int j;
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        for(j = 0; j < cache.size(); j++) {
            if(cities[i] == cache[j]) {
                cache.erase(cache.begin() + j);
                cache.push_back(cities[i]);
                answer += 1;
                break;
            }
        }
        if(j == cache.size()) {
            if(cacheSize <= cache.size()) {
                cache.erase(cache.begin());
            }
            cache.push_back(cities[i]);
            answer += 5;
        }
    }
    return answer;
}