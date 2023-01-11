#include <string>
#include <vector>

#include <iostream>

using namespace std;

const int N = 10;

pair < string, string > num[N] = {{"zero", "0"},
                                 {"one", "1"},
                                 {"two", "2"},
                                 {"three", "3"},
                                 {"four", "4"},
                                 {"five", "5"},
                                 {"six", "6"},
                                 {"seven", "7"},
                                 {"eight", "8"},
                                 {"nine", "9"}};

long long solution(string numbers) {
    long long answer = 0;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        while(true) {
            if(numbers.find(num[i].first) == string::npos) break;
            else numbers.replace(numbers.find(num[i].first), num[i].first.size(), num[i].second);
        }
    }
    answer = stol(numbers);
    return answer;
}