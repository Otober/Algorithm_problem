#include <iostream>
#include <algorithm>
#define N 55

using namespace std;

struct human {
    int weight;
    int height;
} arr[N];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i< n; i++) {
        cin >> arr[i].weight >> arr[i].height;
    }
    
    for(int i = 0; i < n; i++) {
        int temp = 1;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(arr[i].weight < arr[j].weight && arr[i].height < arr[j].height) {
                temp++;
            }
        }
        cout << temp << " ";
    }
    return 0;
}