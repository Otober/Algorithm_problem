#include <string>
#include <vector>

using namespace std;

vector < vector < int > > f_rotate(vector < vector < int > > key) {
    vector < vector < int > > new_key;
    int n = key.size();
    for(int j = 0; j < n; j++) {
        vector < int > temp;
        for(int i = n - 1; i >= 0; i--) {
            temp.push_back(key[i][j]);
        }
        new_key.push_back(temp);
    }
    return new_key;
}

bool f_check(int p, int q, vector < vector < int > > key, vector < vector < int > > board) {
    int key_size = key.size();
    int board_size = board.size();
    for(int i = 0; i < key_size; i++) {
        for(int j = 0; j < key_size; j++) {
            board[i + p][j + q] += key[i][j];
        }
    }
    
    for(int i = key_size - 1; i < board_size - key_size + 1; i++) {
        for(int j = key_size - 1; j < board_size - key_size + 1; j++) {
            if(board[i][j] != 1) return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    int board_size = 2 * (key.size() - 1) + lock.size();
    int key_size = key.size();
    int lock_size = lock.size();
    vector < vector < int > > board(board_size, vector < int > (board_size, 0));
    
    for(int i = 0; i < lock_size; i++) {
        for(int j = 0; j < lock_size; j++) {
            board[i + key_size - 1][j + key_size -1] = lock[i][j];
            if(lock[i][j] == 0) answer = false;
        }
    }
    if(answer) return true;
    for(int k = 0; k < 4; k++) {
        key = f_rotate(key);
        for(int i = 0; i < board_size - key_size + 1; i++) {
            for(int j = 0; j < board_size - key_size + 1; j++) {
                answer = f_check(i, j, key, board);
                if(answer) break;
            }
            if(answer) break;
        }
        if(answer) break;
    }
    return answer;
}