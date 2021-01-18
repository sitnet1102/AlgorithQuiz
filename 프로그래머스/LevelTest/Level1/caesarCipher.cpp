#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i=0;i<s.size();i++){
        int a = s[i];
        char tmp = s[i];
        if(s[i] > 64 && s[i] < 91){
            a = a + n;
            if(a > 90){
                a = a - 26;
            }
        }else if(s[i] > 96 && s[i] < 123){
            a = a + n;
            if(a > 122){
                a = a - 26;
            }
        }
        tmp = (char)a;
        answer = answer + tmp;
    }
    return answer;
}