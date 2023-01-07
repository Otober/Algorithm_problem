#include <string>
#include <vector>

#include <iostream>

using namespace std;

int f_gcd(int a, int b) {
    return b == 0 ? a : f_gcd(b, a %b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int gcd;
    if(arrayA.size() >= 2) {
       gcd = f_gcd(arrayA[0], arrayA[1]);    
    }
    else gcd = arrayA[0];
    bool flag = true;
    for(int i = 2; i < arrayA.size(); i++) {
        gcd = f_gcd(gcd, arrayA[i]);
    }
    for(int i = 0; i < arrayB.size(); i++) {
        if(arrayB[i] % gcd == 0) {
            flag = false;
            break;
        } 
    }
    if(flag) answer = (answer > gcd) ? answer : gcd;
    
    if(arrayB.size() >= 2) {
        gcd = f_gcd(arrayB[0], arrayB[1]);    
    }
    else gcd = arrayB[0];
    flag = true;
    for(int i = 2; i < arrayB.size(); i++) {
        gcd = f_gcd(gcd, arrayB[i]);
    }
    for(int i = 0; i < arrayA.size(); i++) {
        if(arrayA[i] % gcd == 0) {
            flag = false;
            break;
        } 
    }
    if(flag) answer = (answer > gcd) ? answer : gcd;
    
    return answer;
}