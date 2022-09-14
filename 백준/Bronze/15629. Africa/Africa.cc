#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int cost = 0;
    bool SAexists = false;
    bool ZIexists = false;
    bool ZAExists = false;
    
    for(int i = 0; i < n; i++) {
        string st;
        cin >> st;
        if(st == "botswana") cost += 0;
        else if(st == "ethiopia") cost += 50;
        else if(st == "kenya") cost += 50;
        else if(st == "namibia") {
            if(SAexists) cost += 40;
            else cost += 140;
        }
        else if(st == "south-africa") SAexists = true;
        else if(st == "tanzania") cost += 50;
        else if(st == "zambia") {
            ZAExists = true;
            if(ZIexists) cost += 20;
            else cost += 50;
        }
        else if(st == "zimbabwe") {
            ZIexists = true;
            if(ZAExists) cost += 0;
            else cost += 30;
        }
        
        if(st != "zambia" && st != "zimbabwe") {
            ZAExists = false;
            ZIexists = false;
        }
    }
    cout << cost;
    return 0;
}