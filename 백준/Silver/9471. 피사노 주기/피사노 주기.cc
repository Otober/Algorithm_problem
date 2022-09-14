#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        int cnt = 0;
        int f1 = 0;
        int f2 = 1;
        cin >> n >> m;
        do {
            int temp = f1;
            f1 = f2;
            f2 = (temp + f2) % m;
            cnt++;
        }while(f1 != 0 || f2 != 1);
        cout << n << " " << cnt << "\n";
    }
    return 0;
}