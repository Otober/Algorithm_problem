#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for(auto iter1 = phone_book.begin(); iter1 != phone_book.end(); iter1++) {
        for(auto iter2 = iter1; iter2 != phone_book.end(); iter2++) {
            if(iter1 != iter2) {
                if(iter2->find(*iter1) == 0) return false;
                else break;
            }
        }
    } 
    return answer;
}