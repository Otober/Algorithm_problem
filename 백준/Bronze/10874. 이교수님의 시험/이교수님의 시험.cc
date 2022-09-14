#include <iostream>
#include <vector>

using namespace std;

const int N = 10;

vector < int > v;
vector < int > ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        v.clear();
        for(int j = 0; j < N; j++) {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        bool flag = true;
        for(int j = 1; j <= N; j++) {
            if(v[j - 1] != ((j - 1) % 5) + 1) {
                flag = false;
                break;
            }
        }
        if(flag) ans.push_back(i);
    }
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}