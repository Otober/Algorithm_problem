#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

const int N = 3;
const int answer = 123456789;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int board[N * N] = {};

queue < int > q;

map < int, int > mp;

bool f_check(int y, int x) {
    if(y < 0 || y >= N) return false;
    if(x < 0 || x >= N) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int temp = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i * N + j];
            if(board[i * N + j] == 0) board[i * N + j] = 9;
            temp *= 10;
            temp += board[i * N + j];
        }
    }
    
    q.push(temp);
    mp.insert(make_pair(temp, 0));
    
    while(!q.empty()) {
        int now_num = q.front();
        string now = to_string(now_num);
        q.pop();
        
        int z = now.find('9');
        int y = z / 3;
        int x = z % 3;
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(f_check(ny, nx)) {
                string next = now;
                swap(next[y * N + x], next[ny * N + nx]);
                
                int num = stoi(next);
                if(mp.find(num) == mp.end()) {
                    mp.insert(make_pair(num, mp[now_num] + 1));
                    q.push(num);
                }
            }
        }
    }
    if(mp.find(answer) == mp.end()) cout << "-1";
    else cout << mp.find(answer) -> second;
    return 0;
}