#include <iostream>
#include <string>

using namespace std;

const int Alphabets = 26;

int arr[Alphabets] = {};

string st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    cin >> st;
    for(int i = 0; i < st.size(); i++) {
        arr[st[i] - 'a']++;
    }
    for(int i = 0; i < Alphabets; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}