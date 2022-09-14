#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    int arr[55] = {};
    int temp = 0;
    int sum = 0;
    int cnt = 0;
    cin >> str;
    
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '-') {
            sum += temp;
            arr[cnt] = sum;
            cnt++;
            temp = 0;
            sum = 0;
        }
        else if(str[i] == '+') {
            sum += temp;
            temp = 0;
        }
        else {
            temp *= 10;
            temp += str[i] - '0';
        }
    }
    
    sum += temp;
    arr[cnt] += sum;
    
    sum = arr[0];
    
    for(int i = 1; i <= cnt; i++) {
        sum -= arr[i];
    }
    
    cout << sum;
    return 0;
}