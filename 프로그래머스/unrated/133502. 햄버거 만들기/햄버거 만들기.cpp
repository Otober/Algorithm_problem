#include <string>
#include <vector>

using namespace std;

vector < int > v;

bool f_check() {
    int n = v.size() - 1;
    bool flag = true;
    if(v[n] != 1) flag = false;  
    else if(v[n - 1] != 3) flag = false;
    else if(v[n - 2] != 2) flag = false;
    else if(v[n - 3] != 1) flag = false;
    return flag;
}

int solution(vector<int> ingredient) {
    int answer = 0;
    for(int i = 0; i < ingredient.size(); i++) {
        v.push_back(ingredient[i]);
        if(v.size() >= 4) {
            if(f_check()) {
                answer++;
                for(int j = 0; j < 4; j++) {
                    v.erase(v.end() - 1);
                }
            }
        }
    }
    return answer;
}