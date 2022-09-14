#include <iostream>
#include <climits>

using namespace std;

int main() {
    int i_max = INT_MIN;
    int n_max;
    for(int i = 1; i < 10; i++) {
        int temp;
        cin >> temp;
        if(i_max < temp) {
            i_max = temp;
            n_max = i;
        }
    }
    cout << i_max << endl;
    cout << n_max << endl;
}
