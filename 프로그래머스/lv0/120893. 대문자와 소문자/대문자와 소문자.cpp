#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    for(int i = 0; i < my_string.size(); i++) {
        if(my_string[i] >= 'a' && my_string[i] <= 'z') my_string[i] = toupper(my_string[i]);
        else my_string[i] = tolower(my_string[i]);
    }
    return my_string;
}