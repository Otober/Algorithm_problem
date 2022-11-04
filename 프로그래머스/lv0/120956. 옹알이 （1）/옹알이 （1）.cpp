#include <string>
#include <vector>

using namespace std;

string baby[4] = {"ma", "ye", "woo", "aya"};

int solution(vector<string> babbling) {
    int answer = 0;
    for(int k = 0; k < babbling.size(); k++) {
        string str = babbling[k];
        bool f_flag = true;
        for(int i = 0; i < str.size(); i++) {
            bool flag = false;
            string st = str.substr(i, 2);
            for(int j = 0; j < 2; j++) {
                if(st.compare(baby[j]) == 0) {
                    flag = true;
                    i += 1;
                    break;
                }
            }
            if(flag == false) {
                st = str.substr(i, 3);
                for(int j = 2; j < 4; j++) {
                    if(st.compare(baby[j]) == 0) {
                        flag = true;
                        i += 2;
                        break;
                    }
                }
            }
            if(flag == false) {
                f_flag = false;
                break;
            }
        }
        if(f_flag == true) {
            answer++;
        }
    }
    return answer;
}