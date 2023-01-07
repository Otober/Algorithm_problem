#include <string>
#include <vector>

using namespace std;

string str[] = {"ye", "ma", "aya", "woo"};

int solution(vector<string> babbling) {
    int answer = 0;
    for(int k = 0; k < babbling.size(); k++) {
        string st = babbling[k];
        bool flag;
        int before = -1;
        for(int i = 0; i < st.size(); i++) {
            flag = false;
            if(i + 2 <= st.size()) {
                string temp = st.substr(i, 2);
                for(int j = 0; j < 2; j++) {
                    if(str[j] == temp && before != j) {
                        flag = true;
                        i += 1;
                        before = j;
                        break;
                    }
                }
            }
            if(flag == false) {
                if(i + 3 <= st.size()) {
                    string temp = st.substr(i, 3);
                    for(int j = 2; j < 4; j++) {
                        if(str[j] == temp && before != j) {
                            i += 2;
                            before = j;
                            flag = true;
                            break;
                        }
                    }
                }
            }
            
            if(flag == false) break;
            else if(i == st.size() - 1) answer++;
        }
    }
    return answer;
}