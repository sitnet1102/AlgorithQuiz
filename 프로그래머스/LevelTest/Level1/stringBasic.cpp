#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;

    for(int i=0;i<s.size();i++){
        if(s[i] < 48 || s[i] > 57){
            return false;
        }
    }

    if(s.size() != 4 && s.size() != 6){
        return false;
    }

    return answer;
}