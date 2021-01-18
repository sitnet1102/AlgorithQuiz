#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int i=0;
    bool check = false;
    if(s[0] == 43){
        i++;
    }else if(s[0] == 45){
        i++;
        check = true;
    }
    for(;i<s.size();i++){
        int tmp = (int)s[i] - 48;
        answer = answer * 10 + tmp;
    }
    if(check){
        answer = answer * (-1);
    }
    return answer;
}