#include <string>
#include <vector>
#include <set>

using namespace std;

set < string > s;

bool solution(vector<string> phone_book) {
    for(int i = 0; i < phone_book.size(); i++) {
        s.insert(phone_book[i]);
    }
    for(auto iter1 = s.begin(); iter1 != s.end(); iter1++) {
        for(auto iter2 = iter1; iter2 != s.end(); iter2++) {
            if(iter1 != iter2) {
                if(iter2->find(*iter1) == 0) return false;
                else break;
            }
        }
    } 
    return true;
}