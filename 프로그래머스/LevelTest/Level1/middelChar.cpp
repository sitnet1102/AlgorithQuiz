#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    int n = s.size();
    if(n%2 == 0){
        answer = s[n/2 -1];
        answer = answer + s[n/2];
    }else{
        answer = s[n/2];
    }

    //cout << n;
    return answer;
}