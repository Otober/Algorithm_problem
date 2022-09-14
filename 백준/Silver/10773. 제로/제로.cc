#include <iostream>
#include <stack>

using namespace std;

stack < int > st;

int main() {
    int k;
    int sum = 0;
    cin >> k;
    for(int i = 0; i < k; i++) {
        int temp;
        cin >> temp;
        if(temp == 0) st.pop();
        else st.push(temp);
    }
    while(!st.empty()) {
        sum += st.top();
        st.pop();
    }
    cout << sum;
    return 0;
}