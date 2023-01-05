#include <string>
#include <vector>
#include <numeric>

using namespace std;

__int128 solution(int balls, int share) {
    auto v = vector<__int128>(balls - share + 1);
    v[0] = 1;
    for(__int128 i = 0; i < share; i++) {
        for(__int128 j = 1; j < (__int128)v.size(); j++) {
            v[j] += v[j - 1];
        }
    }
    return accumulate(v.begin(), v.end(), (__int128)0);
}