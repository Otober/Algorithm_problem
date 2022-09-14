#include <iostream>
#include <climits>
#define N 1000005

using namespace std;

int main() {
    int n;
    int i_min = INT_MAX;
    int i_max = INT_MIN;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if(i_max < temp) i_max = temp;
        if(i_min > temp) i_min = temp;
    }
    
    cout << i_min << " " << i_max << endl;
}
