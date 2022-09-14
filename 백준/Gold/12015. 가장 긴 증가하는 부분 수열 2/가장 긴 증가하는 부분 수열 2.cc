#include <iostream>
#include <vector>
#define N 1000005
#define INF 987654321

using namespace std;

int arr[N] = {};
vector < int > adj;

int f_max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if(adj.empty() || adj.back() < temp) adj.push_back(temp);
        else {
            vector < int > :: iterator iter = lower_bound(adj.begin(), adj.end(), temp);
            *iter = temp;
        }
    }
    cout << adj.size() << endl;
    return 0;
}