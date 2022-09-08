#include <string>
#include <vector>
#include <map>

using namespace std;

const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

map < pair < int, int >, int > vertex_visited;
map < pair < pair < int, int > , pair < int, int > >, int > edge_visited;

int solution(vector<int> arrows) {
    int answer = 0;
    int x = 0;
    int y = 0;
    vertex_visited[{y, x}] = 1;
    for(int i = 0; i < arrows.size(); i++) {
        for(int j = 0; j < 2; j++) {
            int ny = y + dy[arrows[i]];
            int nx = x + dx[arrows[i]];
            
            if(vertex_visited[{ny, nx}] == 1) {
                if(edge_visited[{{y, x}, {ny, nx}}] == 0 || edge_visited[{{ny, nx}, {y, x}}] == 0) {
                    answer++;
                }
            }
            
            vertex_visited[{y, x}] = 1;
            edge_visited[{{y, x}, {ny, nx}}] = 1;
            edge_visited[{{ny, nx}, {y, x}}] = 1;
            y = ny;
            x = nx;
        }
    }
    return answer;
}