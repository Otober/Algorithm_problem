#include <string>
#include <vector>

using namespace std;

int end_time_to_num(string st) {
    int temp = 0;
    temp += stoi(st.substr(0, 2)) * 60 * 60 * 1000;
    temp += stoi(st.substr(3, 2)) * 60 * 1000;
    temp += stoi(st.substr(6, 2)) * 1000;
    temp += stoi(st.substr(9, 3));
    return temp;
}

int process_to_num(string st) {
    int temp = 0;
    temp += stod(st.substr(13)) * 1000;
    return temp;
}

int solution(vector<string> lines) {
    int answer = 0;
    vector < int > end, process;
    for(int i = 0; i < lines.size(); i++) {
        string st = lines[i].substr(11);
        end.push_back(end_time_to_num(st));
        process.push_back(process_to_num(st));
    }
    for(int i = 0; i < lines.size(); i++) {
        int cnt = 0;
        int second = end[i] + 1000;
        for(int j = i + 1; j < lines.size(); j++) {
            int start = end[j] - process[j] + 1;
            if(start < second) cnt++;
        }
        if(cnt > answer) answer = cnt;
    }
    return answer + 1;
}