#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int num = s.size();
    for(int i=0;i<num;i++){
        char tmp = s.at(i);
        if(tmp < 48 || tmp > 57){
            answer = false;
            break;
        }
    }
    if(num == 4 || num == 6){

    }else{
        answer  = false;
    }
    return answer;
}