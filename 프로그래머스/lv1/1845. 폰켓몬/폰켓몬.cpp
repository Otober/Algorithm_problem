#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int cnt = 1;
    sort(nums.begin(), nums.end());
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] != nums[i - 1]) cnt++;
    }
    cout << nums.size() << " " << cnt;
    return answer = (nums.size() / 2 > cnt) ? cnt : nums.size() / 2;
}