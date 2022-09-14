#include <iostream>
#include <string>

using namespace std;

const int Alphabets = 26;

string st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int lower, upper, number, blank;
    string st;
    
    while(getline(cin, st)) {
        lower = 0;
        upper = 0;
        number = 0;
        blank = 0;
        
        for(int i = 0; i < st.size(); i++) {
            if(st[i] >= 'a' && st[i] <= 'z') lower++;
            else if(st[i] >= 'A' && st[i] <= 'Z') upper++;
            else if(st[i] >= '0' && st[i] <= '9') number++;
            else blank++;
        }
        
        cout << lower << " " << upper << " " << number << " " << blank << "\n";
    }
    return 0;
}