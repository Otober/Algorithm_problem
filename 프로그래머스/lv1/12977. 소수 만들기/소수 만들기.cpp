#include <vector>
#include <iostream>

using namespace std;

const int N = 3005;

bool prime[N] = {};

int solution(vector<int> nums) {
    int answer = 0;
    for(int i = 2; i <= N / 2; i++) {
        for(int j = 2; j * i < N; j++) {
            prime[i * j] = true;
        }
    }
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            for(int k = j + 1; k < nums.size(); k++) {
                if(prime[nums[i] + nums[j] + nums[k]] == false) answer++;
            }
        }
    }
    return answer;
}