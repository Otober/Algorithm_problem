#include <string>

using namespace std;

const int N = 15;
const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

bool visit[N][N][N][N] = {};

bool f_check(pair < int, int > now, pair < int, int > next) {
    if(next.first < 0 || next.first > 10) return false;
    if(next.second < 0 || next.second > 10) return false;
    return true;
}

int solution(string dirs) {
    int answer = 0;
    int direction = 0;
    pair < int, int > now = make_pair(5, 5);
    for(int i = 0; i < dirs.size(); i++) {
        char st = dirs[i];
        if(st == 'U') direction = 0;
        else if(st == 'D') direction = 1;
        else if(st == 'R') direction = 2;
        else if(st == 'L') direction = 3;
        
        pair < int, int > next = make_pair(now.first + dy[direction], now.second + dx[direction]);
        if(f_check(now, next)) {
            if(!visit[now.first][now.second][next.first][next.second] && !visit[next.first][next.second][now.first][now.second]) answer++;
            visit[now.first][now.second][next.first][next.second] = true;
            visit[next.first][next.second][now.first][now.second] = true;
            now = next;
        }
    }
    return answer;
}